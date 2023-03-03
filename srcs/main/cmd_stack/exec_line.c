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

static void	exec_pipe_cmd(void *line, size_t i, int is_first, int is_last)
{
	t_cmd	*cmd;

	// printf("exec_pipe_cmd: %lu\n", i);
	cmd = new_cmd((const char *) line);
	if (cmd == NULL || cmd->args_count == 0)	// Verificar com mais de um comando
		return ;	// Exibir mensagem de erro
	exec_cmd(cmd, is_first, is_last);
	clear_cmd(cmd);
	is_first = is_first;
	is_last = is_last;
	i = i;
}

//      isl=0 | isl=0  | isl=1
//      isf=1 | isf=0  | isf=0
//       i=0  |  i=1   | i=2
//      ls -l | grep a | wc -l
// IN:  STDIN |  PIPE  | PIPE
// OUT:  PIPE |  PIPE  | STDOUT

void	exec_line(const char *line)
{
	t_ftlist	pipe_list;

	pipe_list = pipe_split_line(line);
	ft_lst_func_apply(&pipe_list, exec_pipe_cmd);
	// wait(NULL);
	ft_lst_clear(&pipe_list, free);
	dup2(g_core.std_in, STDIN_FILENO);
	dup2(g_core.std_out, STDOUT_FILENO);
}

/*static void	print_redir(void *slice, size_t i, int isf, int isl)
{
	printf("\t%lu) type: ", i);
	switch (((t_slice *) slice)->type) {
		case (REDIR_OUT): {printf(">"); break;}
		case (REDIR_APPEND): {printf(">>"); break;}
		case (REDIR_IN): {printf("<"); break;}
		case (REDIR_HEREDOC): {printf("<<"); break;}
	};
	printf(" | \"%s\"\n", ((t_slice *) slice)->start);
	isf = isf;
	isl = isl;
}

static void	print_split(void *content, size_t i, int isf, int isl)
{
	t_ftlist	redirs;

	printf("%lu) line: \"%s\"\n", i, (const char *) content);
	redirs = redir_split_line(content);
	ft_lst_func_apply(&redirs, print_redir);
	ft_lst_clear(&redirs, free);
	isf = isf;
	isl = isl;
}

void	exec_line(const char *line)
{
	t_ftlist	pipe_list;

	pipe_list = pipe_split_line(line);
	ft_lst_func_apply(&pipe_list, print_split);
	ft_lst_clear(&pipe_list, free);
}
*/

// void	pipex(t_data *data)
// {
// 	int		i;
// 	pid_t	w;
// 	int		wstatus;

// 	if (data->fd_infile != -1)
// 	{
// 		dup2(data->fd_infile, STDIN_FILENO);
// 		close(data->fd_infile);
// 	}
// 	i = 0;
// 	while (i < data->cmd_count)
// 	{
// 		// -- Inicio loop func --
// 		if (i > 0)	// Verificar se não é o primeiro comando
// 		{
// 			dup2(data->fd[0], STDIN_FILENO);
// 			close(data->fd[0]);
// 		}
// 		if (pipe(data->fd) == -1)	// Verificar se o pipe deu errado
// 			error(data, NULL);
// 		data->pid = fork();
// 		if (data->pid == -1)
// 			error(data, NULL);
// 		if (data->pid == 0)		// Verificar se é o processo filho
// 		{
// 			if (i == 0 && data->fd_infile == -1)
// 				error(data, NULL);

// 			// -- Inicio exec cmd --
// 			char	**cmd;
// 			char	*cmd_path;

// 			if (i == data->cmd_count - 1)	// Verificar se é o último comando
// 			{
// 				data->fd_outfile = open(
// 						data->argv[data->argc - 1],
// 						O_WRONLY | O_CREAT | O_TRUNC, 0664);
// 				if (data->fd_outfile == -1)
// 					error(data, NULL);
// 				dup2(data->fd_outfile, STDOUT_FILENO);
// 			}
// 			else	// Caso não seja o último comando
// 				dup2(data->fd[1], STDOUT_FILENO);

// 			cmd = decode_cmd(data->argv[i + 2]);
// 			cmd_path = get_cmd_path(data, cmd[0]);
// 			if (cmd_path == NULL)
// 				error_cmd_not_found(data, cmd);
// 			close(data->fd_outfile);
// 			close(data->fd[1]);
// 			execve(cmd_path, cmd, data->envp);
// 			exit(EXIT_FAILURE);
// 			// -- Fim exec cmd --

// 		}
// 		// -- Fim loop func --

// 		w = waitpid(data->pid, &wstatus, 0);
// 		if (w == -1)
// 			error(data, NULL);
// 		if (WIFEXITED(wstatus)	// Verifica se saiu corretamente do processo
// 			&& i == data->cmd_count - 1	// Verifica se é o último comando
// 			&& WEXITSTATUS(wstatus) != 0)	// Verifica se o último comando não deu erro
// 		{
// 			if (data != NULL && data->paths != NULL)
// 				clean_array(data->paths);
// 			exit(WEXITSTATUS(wstatus));
// 		}
// 		close(data->fd[1]);
// 		i += 1;
// 	}
// }


// ls -l | ls -l

// pipe: [3, 4]
// IN: 3
// OUT: STDOUT

// 1) ls -l
//		is_first: 1
//		is_last: 0
// 2) ls -l
//		is_first: 0
//		is_last: 1