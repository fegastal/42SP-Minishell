/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_arg_required_error.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:45:28 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/16 21:35:38 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	numeric_arg_required_error(void)
{
	error(ERR_CUSTOM_ERROR, "Error: Numeric argument required\n");
	g_core.last_status = ERR_NUMERIC_ARGUMENT_REQUIRED;
	return (ERR_NUMERIC_ARGUMENT_REQUIRED);
}
