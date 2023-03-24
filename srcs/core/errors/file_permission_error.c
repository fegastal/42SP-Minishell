/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_permission_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:54:53 by fgastal-          #+#    #+#             */
/*   Updated: 2023/03/14 22:54:53 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

/*
	Prints an error message related to file permission and updates the
	control variables of the g_core structure.
*/
int	file_permission_error(void)
{
	error(ERR_FILE_NO_PERMISSION, NULL);
	g_core.last_status = ERR_SYNTAX_ERROR;
	return (0);
}
