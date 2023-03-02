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

void exec_cmd(t_cmd *cmd, int is_first, int is_last)
{
	int		wstatus;
	int		tmp;

	if (is_builtin(cmd->args[0]))
		call_builtin(cmd);
	else
	{
		tmp = g_core.pipe[0];
		if (pipe(g_core.pipe) == -1)
			exit(EXIT_FAILURE);

		g_core.last_pid = fork();
		if (g_core.last_pid == 0)
		{
			if (!is_first)
			{
				dup2(tmp, STDIN_FILENO);
				close(tmp);
			}
			if (is_first && is_last)
			{
				dup2(g_core.std_in, STDIN_FILENO);
				dup2(g_core.std_out, STDOUT_FILENO);
			}
			else if (is_last)
				dup2(g_core.std_out, STDOUT_FILENO);
			else if (!is_last)
			{
				dup2(g_core.pipe[1], STDOUT_FILENO);
				close(g_core.pipe[1]);
			}
			wstatus = execve(cmd->path, cmd->args, g_core.envp);
			if (wstatus == -1)
				exit(EXIT_FAILURE);	// Tratar erro de comando inválido
		}
		close(g_core.pipe[1]);
		waitpid(g_core.last_pid, &wstatus, 0);
		g_core.last_status = WEXITSTATUS(wstatus);
	}
}
