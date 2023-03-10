/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:51:17 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/08 19:51:17 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
