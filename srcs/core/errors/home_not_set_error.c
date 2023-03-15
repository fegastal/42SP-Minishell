/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_not_set_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:54:53 by fgastal-          #+#    #+#             */
/*   Updated: 2023/03/14 22:54:53 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

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
