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

void call_builtin(t_cmd *cmd)
{
	char *name;

	name = cmd->args[0];
	if (!ft_strcmp(name, "echo"))
		builtin_echo(cmd);
	else if (!ft_strcmp(name, "export"))
		builtin_export(cmd);
	else if (!ft_strcmp(name, "pwd"))
		builtin_pwd();
	else if (!ft_strcmp(name, "unset"))
		builtin_unset(cmd);
	else if (!ft_strcmp(name, "env"))
		ft_printf("env builtin function\n");
	else if (!ft_strcmp(name, "cd"))
		ft_printf("cd builtin function\n");
	else if (!ft_strcmp(name, "exit"))
		builtin_exit(cmd);
}
