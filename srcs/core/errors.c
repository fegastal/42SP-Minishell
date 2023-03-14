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

/*
	Displays a custom error message in the
	standard error output and sets the value of last_status
	to the corresponding error code.
*/
int	syntax_error(void)
{
	error(ERR_CUSTOM_ERROR, "Error: Syntax error\n");
	g_core.last_status = ERR_SYNTAX_ERROR;
	g_core.can_proceed = 0;
	return (0);
}

/*
	Prints an error message related to file permission and updates the
	control variables of the g_core structure.
*/
int	file_permission_error(void)
{
	error(ERR_FILE_NO_PERMISSION, NULL);
	g_core.last_status = ERR_SYNTAX_ERROR;
	// g_core.can_proceed = 0;
	return (0);
}

/*
	Prints an error message indicating invalid arguments in an
	internal command (builtin).
*/
int	wrong_builtin_args_error(void)
{
	error(ERR_WRONG_BUILTIN_ARGS, NULL);
	g_core.last_status = ERR_WRONG_BUILTIN_ARGS;
	g_core.can_proceed = 0;
	return (ERR_WRONG_BUILTIN_ARGS);
}

/*
	Displays an error message stating that the HOME
	environment variable has not been set and set
	g_core.last_status to the corresponding error code.
*/
int	home_not_set_error(void)
{
	error(ERR_CUSTOM_ERROR, "Error: HOME not set\n");
	g_core.last_status = ERR_HOME_NOT_SET;
	g_core.can_proceed = 0;
	return (ERR_HOME_NOT_SET);
}

/*
	Displays an error message indicating that the file
	or directory does not exist.
*/
int	no_such_file_or_dir_error(void)
{
	error(ERR_NO_SUCH_FILE_OR_DIR, NULL);
	g_core.last_status = ERR_NO_SUCH_FILE_OR_DIR;
	g_core.can_proceed = 0;
	return (ERR_NO_SUCH_FILE_OR_DIR);
}
