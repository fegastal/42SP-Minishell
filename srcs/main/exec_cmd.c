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

void exec_cmd(t_cmd *cmd, char **envp)
{
	int pid;

	if (is_builtin(cmd->args[0]))
		call_builtin(cmd);
	else
	{
		pid = fork();
		if (pid == 0)
			execve(cmd->path, cmd->args, envp);
	}
}
