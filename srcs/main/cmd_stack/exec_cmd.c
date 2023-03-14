/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:14:05 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/07 22:14:05 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_process(t_cmd_executor *executor);
static void	handle_child_redirs(t_cmd_executor *executor);

/*
	The function is responsible for executing a command in
	a new child process, based on a t_cmd structure supplied
	as a parameter, using fork() and waitpid().
*/
void	exec_cmd(t_cmd *cmd, int is_first, int is_last)
{
	t_cmd_executor	executor;

	executor = (t_cmd_executor){
		.cmd = cmd,
		.is_first = is_first,
		.is_last = is_last,
		.wstatus = -1,
		.last_pipe_in = g_core.pipe[0]
	};
	if (pipe(g_core.pipe) == -1)
		exit(EXIT_FAILURE);
	g_core.last_pid = fork();
	if (g_core.last_pid == 0)
		child_process(&executor);
	close(g_core.pipe[1]);
	waitpid(g_core.last_pid, &(executor.wstatus), 0);
	g_core.last_status = WEXITSTATUS(executor.wstatus);
}

static void	child_process(t_cmd_executor *executor)
{
	handle_child_redirs(executor);
	if (executor->cmd->is_builtin)
		executor->wstatus = call_builtin(executor->cmd);
	else
	{
		executor->wstatus = execve(
				executor->cmd->path,
				executor->cmd->args, g_core.envp);
	}
	if (executor->wstatus == -1)
	{
		if (!executor->cmd->is_builtin && executor->cmd->path == NULL)
		{
			error(ERR_CMD_NOT_FOUND, executor->cmd->args[0]);
			exit(ERR_CMD_NOT_FOUND);
		}
		exit(ERR_FAILURE);
	}
}

static void	handle_child_redirs(t_cmd_executor *executor)
{
	if (g_core.fd_in_type == FD_REDIR_STD)
		dup2(g_core.std_in, STDIN_FILENO);
	else if (g_core.fd_in_type == FD_REDIR_FILE)
		dup2(g_core.fd_in, STDIN_FILENO);
	else if (g_core.fd_in_type == FD_REDIR_PIPE)
		dup2(executor->last_pipe_in, STDIN_FILENO);
	if (g_core.fd_out_type == FD_REDIR_STD)
		dup2(g_core.std_out, STDOUT_FILENO);
	else if (g_core.fd_out_type == FD_REDIR_FILE)
		dup2(g_core.fd_out, STDOUT_FILENO);
	else if (g_core.fd_out_type == FD_REDIR_PIPE)
		dup2(g_core.pipe[1], STDOUT_FILENO);
	if (g_core.fd_out == -1 && g_core.fd_out_type == FD_REDIR_FILE)
		exit(ERR_FAILURE);
	else if (g_core.fd_in == -1 && g_core.fd_in_type == FD_REDIR_FILE)
		exit(ERR_FAILURE);
}
