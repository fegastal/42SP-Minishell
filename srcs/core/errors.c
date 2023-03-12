/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:51:17 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/08 19:51:17 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	syntax_error(void)
{
	error(ERR_CUSTOM_ERROR, "Error: Syntax error\n");
	g_core.last_status = ERR_SYNTAX_ERROR;
	g_core.can_proceed = 0;
	return (0);
}

int	file_permission_error(void)
{
	error(ERR_FILE_NO_PERMISSION, NULL);
	g_core.last_status = ERR_SYNTAX_ERROR;
	g_core.can_proceed = 0;
	return (0);
}

int	wrong_builtin_args_error(void)
{
	error(ERR_WRONG_BUILTIN_ARGS, NULL);
	g_core.last_status = ERR_WRONG_BUILTIN_ARGS;
	g_core.can_proceed = 0;
	return (ERR_WRONG_BUILTIN_ARGS);
}

int	home_not_set_error(void)
{
	error(ERR_HOME_NOT_SET, NULL);
	g_core.last_status = ERR_HOME_NOT_SET;
	g_core.can_proceed = 0;
	return (ERR_HOME_NOT_SET);
}

int	no_such_file_or_dir_error(void)
{
	error(ERR_NO_SUCH_FILE_OR_DIR, NULL);
	g_core.last_status = ERR_NO_SUCH_FILE_OR_DIR;
	g_core.can_proceed = 0;
	return (ERR_NO_SUCH_FILE_OR_DIR);
}
