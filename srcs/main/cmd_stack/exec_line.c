/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:26:18 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/20 12:26:18 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_pipe_line(void *line, size_t i, int is_first, int is_last);
static t_redir_context	open_redir_files(t_ftlist *redir_list);
static void	close_redir_files(void *content, size_t i, int isf, int isl);
// static void	print_redir(void *content, size_t i, int is_first, int is_last); //

// static void	print_pipe(void *line, size_t i, int isf, int isl)
// {
// 	char	*str;

// 	str = ft_xstr_mjoin("", 4, ft_itoa(i), ") ", (char *) line, "\n");
// 	ft_putstr_fd(str, 1);
// 	isf = isf;
// 	isl = isl;
// }

// [PENDENTE]: Verificar parseamento de strings com aspas duplas e simples

void	exec_line(const char *line)
{
	t_ftlist		pipe_list;

	if (ft_xstr_match_set(line, " "))
		return ;
	pipe_list = pipe_split_line(line);

	// DEBUG
	// printf("line: \"%s\"\n", line);
	// ft_lst_func_apply(&pipe_list, print_pipe);

	ft_lst_func_apply(&pipe_list, exec_pipe_line);
	ft_lst_clear(&pipe_list, free);
	// dup2(g_core.std_in, STDIN_FILENO);
	// dup2(g_core.std_out, STDOUT_FILENO);
}

/*
	Open files and return redir context containing first cmd, last outfile and
	last infile.
*/
static t_redir_context	open_redir_files(t_ftlist *redir_list)
{
	t_redir_slice	*slice;
	t_ftnode		*node;
	t_redir_context	context;

	context = (t_redir_context) {0};
	node = redir_list->front;
	while (node != NULL)
	{
		slice = (t_redir_slice *) node->content;
		if (slice->type == REDIR_CMD)
		{
			if (context.first_cmd == NULL)
				context.first_cmd = slice;
			else
				ft_xstr_supplant(&context.first_cmd->str,
						ft_xstr_join(" ", context.first_cmd->str, slice->str));
		}
		else if (slice->type == REDIR_OUT)
		{
			context.last_outfile = slice;
			slice->fd = open(slice->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			// ft_putstr_fd("fd out before: ", 2);
			// ft_putnbr_fd(slice->fd, 2);
			// ft_putstr_fd("\n", 2);
			if (slice->fd == -1)
				error(ERR_FILE_NO_PERMISSION, "");
		}
		else if (slice->type == REDIR_APPEND)
		{
			context.last_outfile = slice;
			slice->fd = open(slice->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (slice->fd == -1)
				error(ERR_FILE_NO_PERMISSION, "");
		}
		else if (slice->type == REDIR_IN)
		{
			context.last_infile = slice;
			slice->fd = open(slice->str, O_RDONLY);
			if (slice->fd == -1)
				error(ERR_FILE_NO_PERMISSION, "");
		}
		else if (slice->type == REDIR_HEREDOC)
		{
			context.last_infile = slice;
			char	*filename = get_tmp_file_name();
			slice->fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (slice->fd == -1)
				error(ERR_FILE_NO_PERMISSION, "");
			// Temporario
			int		pid = fork();
			char	*input;
			if (pid == 0)
			{
				input = readline("> ");
				while (ft_strcmp(input, slice->str))
				{
					write(slice->fd, input, ft_strlen(input));
					write(slice->fd, "\n", 1);
					free(input);
					input = readline("> ");
				}
				free(input);
				exit(0);
			}
			waitpid(pid, NULL, 0);
			close(slice->fd);
			slice->fd = open(filename, O_RDONLY);
			slice->str = filename;
		}
		node = node->next;
	}
	return (context);
}

// static void	print_redir(void *content, size_t i, int is_first, int is_last);

// static void	debug_redir_context(t_redir_context *redir_context)
// {
// 	ft_putstr_fd("Redir context:\n", 2);
// 	ft_putstr_fd("\tfirst_cmd: ", 2);
// 	if (redir_context->first_cmd != NULL)
// 	{
// 		ft_putnbr_fd(redir_context->first_cmd->fd, 2);
// 		ft_putstr_fd(" ", 2);
// 		ft_putstr_fd(redir_context->first_cmd->str, 2);
// 	}
// 	else
// 		ft_putstr_fd("NULL", 2);
// 	ft_putstr_fd("\n", 2);
// 	ft_putstr_fd("\tlast_infile: ", 2);
// 	if (redir_context->last_infile != NULL)
// 	{
// 		ft_putnbr_fd(redir_context->last_infile->fd, 2);
// 		ft_putstr_fd(" ", 2);
// 		ft_putstr_fd(redir_context->last_infile->str, 2);
// 	}
// 	else
// 		ft_putstr_fd("NULL", 2);
// 	ft_putstr_fd("\n", 2);
// 	ft_putstr_fd("\tlast_outfile: ", 2);
// 	if (redir_context->last_outfile != NULL)
// 	{
// 		ft_putnbr_fd(redir_context->last_outfile->fd, 2);
// 		ft_putstr_fd(" ", 2);
// 		ft_putstr_fd(redir_context->last_outfile->str, 2);
// 	}
// 	else
// 		ft_putstr_fd("NULL", 2);
// 	ft_putstr_fd("\n", 2);
// }

static void	exec_pipe_line(void *line, size_t i, int is_first, int is_last)
{
	t_ftlist		redir_list;
	t_redir_context	redir_context;
	t_cmd			*cmd;

	redir_list = redir_split_line((const char *) line);
	redir_context = open_redir_files(&redir_list);

	if (redir_context.last_infile != NULL)
	{
		g_core.fd_in = redir_context.last_infile->fd;
		g_core.fd_in_type = FD_REDIR_FILE;
	}
	else
	{
		if (is_first)
			g_core.fd_in_type = FD_REDIR_STD;
		else
			g_core.fd_in_type = FD_REDIR_PIPE;
	}
	if (redir_context.last_outfile != NULL)
	{
		g_core.fd_out = redir_context.last_outfile->fd;
		g_core.fd_out_type = FD_REDIR_FILE;
	}
	else
	{
		if (is_last)
			g_core.fd_out_type = FD_REDIR_STD;
		else
			g_core.fd_out_type = FD_REDIR_PIPE;
	}
	cmd = new_cmd(redir_context.first_cmd->str);
	if (is_first && is_last && is_builtin(cmd->args[0]))
		g_core.last_status = call_single_builtin(cmd);
	else
		exec_cmd(cmd, is_first, is_last);
	clear_cmd(cmd);
	ft_lst_func_apply(&redir_list, close_redir_files);
	ft_lst_clear(&redir_list, free);
	i = i;
}

static void	close_redir_files(void *content, size_t i, int isf, int isl)
{
	t_redir_slice	*slice;

	slice = (t_redir_slice *) content;
	if (slice->str != NULL)
		free(slice->str);
	if (slice->type == REDIR_OUT || slice->type == REDIR_APPEND
		|| slice->type == REDIR_IN || slice->type == REDIR_HEREDOC)
	{
		close(slice->fd);
		if (slice->type == REDIR_HEREDOC)
			unlink(slice->str);
	}
	isf = isf;
	isl = isl;
	i = i;
}

// static void	print_redir(void *content, size_t i, int is_first, int is_last)
// {
// 	t_redir_slice	*token;

// 	token = (t_redir_slice *) content;
// 	printf("token->start: \"%s\"\n", token->str);
// 	printf("token->type: (%i) ", token->type);
// 	switch (token->type)
// 	{
// 		case REDIR_NONE: { printf("REDIR_NONE"); break; }
// 		case REDIR_IN: { printf("REDIR_IN"); break; }
// 		case REDIR_OUT: { printf("REDIR_OUT"); break; }
// 		case REDIR_APPEND: { printf("REDIR_APPEND"); break; }
// 		case REDIR_HEREDOC: { printf("REDIR_HEREDOC"); break; }
// 		case REDIR_CMD: { printf("REDIR_CMD"); break; }
// 	}
// 	printf("\nfd: %i\n\n", token->fd);
// 	is_first = is_first;
// 	is_last = is_last;
// 	i = i;
// }

// static void	exec_pipe_cmd(void *line, size_t i, int is_first, int is_last)
// {
// 	t_cmd	*cmd;

// 	cmd = new_cmd((const char *) line);
// 	if (cmd == NULL)	// Caso de linha somente com espaços
// 		return ;	// Exibir mensagem de erro
// 	else if (cmd->path == NULL && !cmd->is_builtin)	// Caso de comando não encontrado
// 	{
// 		printf("minishell: %s: command not found\n", cmd->args[0]);
// 		g_core.last_status = 127;
// 		clear_cmd(cmd);
// 		return ;
// 	}
// 	exec_cmd(cmd, is_first, is_last);
// 	if (is_first && is_last && !ft_strcmp(cmd->args[0], "exit"))
// 		g_core.is_running = IS_NOT_RUNNING;
// 	clear_cmd(cmd);
// 	i = i;
// }
