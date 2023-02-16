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
		ft_printf("echo builtin function\n");
	else if (!ft_strcmp(name, "export"))
		ft_printf("export builtin function\n");
	else if (!ft_strcmp(name, "pwd"))
		ft_printf("pwd builtin function\n");
	else if (!ft_strcmp(name, "unset"))
		ft_printf("unset builtin function\n");
	else if (!ft_strcmp(name, "env"))
		ft_printf("env builtin function\n");
	else if (!ft_strcmp(name, "cd"))
		ft_printf("cd builtin function\n");
	else if (!ft_strcmp(name, "exit"))
		ft_printf("exit builtin function\n");
}
