/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_a_valid_identifier_error.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:54:53 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/14 22:54:53 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	not_a_valid_identifier_error(void)
{
	error(ERR_CUSTOM_ERROR, "Error: Not a valid identifier\n");
	g_core.last_status = ERR_NOT_A_VALID_IDENTIFIER;
	return (ERR_NOT_A_VALID_IDENTIFIER);
}
