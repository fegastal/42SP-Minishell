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

// Última tarefa em progresso: Execução de built-in com pipe

static void	child_process(t_cmd_executor *executor);

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
	dup2(g_core.fd_in, STDIN_FILENO);
	dup2(g_core.fd_out, STDOUT_FILENO);
	if (g_core.fd_out == -1)
		exit(EXIT_FAILURE);	// Erro de descritor inválido (provavelmente não aberto)
	if (executor->cmd->is_builtin)
		executor->wstatus = call_builtin(executor->cmd);
	else
		executor->wstatus = execve(
				executor->cmd->path,
				executor->cmd->args, g_core.envp);
	if (executor->wstatus == -1)
		exit(EXIT_FAILURE); // Tratar erro de comando inválido
}

// static void	child_process(t_cmd_executor *executor)
// {
// 	if (!executor->is_first)
// 	{
// 		dup2(executor->last_pipe_in, STDIN_FILENO);
// 		close(executor->last_pipe_in);
// 	}
// 	if (executor->is_first && executor->is_last)
// 	{
// 		dup2(g_core.fd_in, STDIN_FILENO);
// 		dup2(g_core.fd_out, STDOUT_FILENO);
// 		// dup2(g_core.std_in, STDIN_FILENO);
// 		// dup2(g_core.std_out, STDOUT_FILENO);
// 	}
// 	else if (executor->is_last)
// 		dup2(g_core.fd_out, STDOUT_FILENO);
// 		// dup2(g_core.std_out, STDOUT_FILENO);
// 	else if (!executor->is_last)
// 	{
// 		dup2(g_core.pipe[1], STDOUT_FILENO);	// Revisar linha (está redirecionando sempre para a saída do pipe)
// 		close(g_core.pipe[1]);
// 	}
// 	if (executor->cmd->is_builtin)
// 		executor->wstatus = call_builtin(executor->cmd);
// 	else
// 		executor->wstatus = execve(
// 				executor->cmd->path,
// 				executor->cmd->args, g_core.envp);
// 	if (executor->wstatus == -1)
// 		exit(EXIT_FAILURE); // Tratar erro de comando inválido
// }






















// void exec_cmd(t_cmd *cmd, int is_first, int is_last)
// {
// 	int		wstatus;
// 	int		tmp;

// 	wstatus = -1;
// 	tmp = g_core.pipe[0];
// 	if (pipe(g_core.pipe) == -1)
// 		exit(EXIT_FAILURE);
// 	g_core.last_pid = fork();
// 	if (g_core.last_pid == 0)
// 	{
// 		if (!is_first)
// 		{
// 			dup2(tmp, STDIN_FILENO);
// 			close(tmp);
// 		}
// 		if (is_first && is_last)
// 		{
// 			dup2(g_core.std_in, STDIN_FILENO);
// 			dup2(g_core.std_out, STDOUT_FILENO);
// 		}
// 		else if (is_last)
// 			dup2(g_core.std_out, STDOUT_FILENO);
// 		else if (!is_last)
// 		{
// 			dup2(g_core.pipe[1], STDOUT_FILENO);
// 			close(g_core.pipe[1]);
// 		}
// 		if (is_builtin(cmd->args[0]))
// 			wstatus = call_builtin(cmd);
// 		else
// 			wstatus = execve(cmd->path, cmd->args, g_core.envp);
// 		if (wstatus == -1)
// 			exit(EXIT_FAILURE);	// Tratar erro de comando inválido
// 	}
// 	close(g_core.pipe[1]);
// 	waitpid(g_core.last_pid, &wstatus, 0);
// 	g_core.last_status = WEXITSTATUS(wstatus);
// }
