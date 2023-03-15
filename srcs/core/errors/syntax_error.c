/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:54:53 by fgastal-          #+#    #+#             */
/*   Updated: 2023/03/14 22:54:53 by fgastal-         ###   ########.fr       */
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
