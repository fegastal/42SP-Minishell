/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_builtin_args_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:54:53 by fgastal-          #+#    #+#             */
/*   Updated: 2023/03/14 22:54:53 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

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
