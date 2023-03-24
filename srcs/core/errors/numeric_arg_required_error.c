/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_arg_required_error.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:45:28 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/15 15:45:28 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	numeric_arg_required_error(void)
{
	error(ERR_CUSTOM_ERROR, "Error: Numeric argument required\n");
	g_core.last_status = ERR_NUMERIC_ARGUMENT_REQUIRED;
	// g_core.can_proceed = 0;
	return (ERR_NUMERIC_ARGUMENT_REQUIRED);
}
