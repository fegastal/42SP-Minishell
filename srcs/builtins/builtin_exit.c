/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:57:07 by fgastal-          #+#    #+#             */
/*   Updated: 2023/03/16 21:21:26 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	is_numeric_arg(const char *arg);

/*
	The built-in "exit" command terminates the shell
	and returns an exit code to the operating system.
*/
int	builtin_exit(t_cmd *cmd)
{
	const char	*value;
	int			exit_code;

	if (cmd->args_count == 1)
		return (g_core.last_status);
	else if (cmd->args_count > 2)
		return (wrong_builtin_args_error());
	value = cmd->args[1];
	if (value == NULL)
		return (g_core.last_status);
	if (!is_numeric_arg(value))
		return (numeric_arg_required_error());
	exit_code = ft_atoi(value);
	if (exit_code < 0)
		exit_code = 256 + exit_code;
	g_core.is_running = IS_NOT_RUNNING;
	return (exit_code);
}

static int	is_numeric_arg(const char *arg)
{
	if (arg == NULL)
		return (0);
	if (*arg != '+' && *arg != '-' && !ft_str_isdigit(arg))
		return (0);
	if ((*arg == '+' || *arg == '-') && !ft_str_isdigit(arg + 1))
		return (0);
	return (1);
}
