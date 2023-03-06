/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:41:16 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/01/10 13:41:16 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	call_builtin(t_cmd *cmd)
{
	char	*name;
	int		status;

	name = cmd->args[0];
	if (!ft_strcmp(name, "echo"))
		status = builtin_echo(cmd);
	else if (!ft_strcmp(name, "export"))
		status = builtin_export(cmd);
	else if (!ft_strcmp(name, "pwd"))
		status = builtin_pwd();
	else if (!ft_strcmp(name, "unset"))
		status = builtin_unset(cmd);
	else if (!ft_strcmp(name, "env"))
		status = builtin_env(cmd);
	else if (!ft_strcmp(name, "cd"))
		status = builtin_cd(cmd);
	else if (!ft_strcmp(name, "exit"))
	{
		g_core.is_running = IS_NOT_RUNNING;
		exit(builtin_exit(cmd));
	}
	if (status == 0)
		exit(0);
	return (-1);
}

int	call_single_builtin(t_cmd *cmd)
{
	char	*name;
	int		status;

	name = cmd->args[0];
	if (!ft_strcmp(name, "echo"))
		status = builtin_echo(cmd);
	else if (!ft_strcmp(name, "export"))
		status = builtin_export(cmd);
	else if (!ft_strcmp(name, "pwd"))
		status = builtin_pwd();
	else if (!ft_strcmp(name, "unset"))
		status = builtin_unset(cmd);
	else if (!ft_strcmp(name, "env"))
		status = builtin_env(cmd);
	else if (!ft_strcmp(name, "cd"))
		status = builtin_cd(cmd);
	else if (!ft_strcmp(name, "exit"))
	{
		g_core.is_running = IS_NOT_RUNNING;
		status = builtin_exit(cmd);
	}
	return (status);
}
