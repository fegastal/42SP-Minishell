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

void	exec_line(const char *line)
{
	t_ftlist	pipe_list;

	pipe_list = pipe_split_line(line);
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
		if (slice->type == REDIR_CMD && context.first_cmd == NULL)
			context.first_cmd = slice;
		else if (slice->type == REDIR_OUT)
		{
			context.last_outfile = slice;
			slice->fd = open(slice->str, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (slice->fd == -1)
				printf("Error opening file \"%s\"\n", slice->str);
		}
		else if (slice->type == REDIR_APPEND)
		{
			context.last_outfile = slice;
			slice->fd = open(slice->str, O_RDWR | O_CREAT | O_APPEND, 0644);
			if (slice->fd == -1)
				printf("Error opening file \"%s\"\n", slice->str);
		}
		else if (slice->type == REDIR_IN)
		{
			context.first_infile = slice;
			slice->fd = open(slice->str, O_RDONLY);
			if (slice->fd == -1)
				printf("Error opening file \"%s\"\n", slice->str);
		}
		node = node->next;
	}
	return (context);
}

static void	print_redir(void *content, size_t i, int is_first, int is_last);

static void	exec_pipe_line(void *line, size_t i, int is_first, int is_last)
{
	t_ftlist		redir_list;
	// t_ftnode		*node;
	// t_redir_slice	*slice;
	t_redir_context	redir_context;
	t_cmd			*cmd;

	redir_list = redir_split_line((const char *) line);
	redir_context = open_redir_files(&redir_list);
	// if (is_first)	// Posteriormente, adicionar redir de entrada aqui
	// 	g_core.fd_in = g_core.std_in;
	// else
	// 	g_core.fd_in = g_core.pipe[0];
	if (redir_context.first_infile != NULL)
	{
		g_core.fd_in = redir_context.first_infile->fd;
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
	if (1)
		ft_lst_func_apply(&redir_list, print_redir);	// Debug
	cmd = new_cmd(redir_context.first_cmd->str);
	exec_cmd(cmd, is_first, is_last);
	ft_lst_func_apply(&redir_list, close_redir_files);
	// node = redir_list.front;
	// while (node != NULL)
	// {
	// 	slice = (t_redir_slice *) node->content;
	// 	if (slice->type == REDIR_CMD)
	// 		break ;
	// 	node = node->next;
	// }
	is_first = is_first;
	is_last = is_last;
	i = i;
}

static void	close_redir_files(void *content, size_t i, int isf, int isl)
{
	t_redir_slice	*slice;

	slice = (t_redir_slice *) content;
	if (slice->type == REDIR_OUT || slice->type == REDIR_APPEND)
		close(slice->fd);
	isf = isf;
	isl = isl;
	i = i;
}

static void	print_redir(void *content, size_t i, int is_first, int is_last)
{
	t_redir_slice	*token;

	token = (t_redir_slice *) content;
	printf("token->start: \"%s\"\n", token->str);
	printf("token->type: (%i) ", token->type);
	switch (token->type)
	{
		case REDIR_NONE: { printf("REDIR_NONE"); break; }
		case REDIR_IN: { printf("REDIR_IN"); break; }
		case REDIR_OUT: { printf("REDIR_OUT"); break; }
		case REDIR_APPEND: { printf("REDIR_APPEND"); break; }
		case REDIR_HEREDOC: { printf("REDIR_HEREDOC"); break; }
		case REDIR_CMD: { printf("REDIR_CMD"); break; }
	}
	printf("\nfd: %i\n\n", token->fd);
	is_first = is_first;
	is_last = is_last;
	i = i;
}

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
