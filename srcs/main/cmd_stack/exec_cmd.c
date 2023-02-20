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

void exec_cmd(t_cmd *cmd)
{
	int		pid;
	int		wstatus;

	if (is_builtin(cmd->args[0]))
		call_builtin(cmd);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			g_core.last_pid = pid;
			wstatus = execve(cmd->path, cmd->args, g_core.envp);
			if (wstatus == -1)
				exit(WEXITSTATUS(wstatus));
		}
		waitpid(pid, &wstatus, 0);
		g_core.last_status = WEXITSTATUS(wstatus);
	}
}
