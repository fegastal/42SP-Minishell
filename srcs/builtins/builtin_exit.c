/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:57:07 by fgastal-          #+#    #+#             */
/*   Updated: 2023/03/12 16:19:16 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/*
	The built-in "exit" command terminates the shell
	and returns an exit code to the operating system.
*/
int	builtin_exit(t_cmd *cmd)
{
	const char	*value;
	int			exit_code;

	if (cmd->args_count == 1)
		exit(g_core.last_status);
	else if (cmd->args_count > 2)
		return (wrong_builtin_args_error());
	value = cmd->args[1];
	if (value == NULL)
		return (g_core.last_status);
	if (*value != '+' && *value != '-' && !ft_isdigit(*value))
		return (numeric_arg_required_error());
	exit_code = ft_atoi(value);
	if (exit_code < 0)
		exit_code = 256 + exit_code;
	return (exit_code);
}
