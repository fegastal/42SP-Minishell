/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_ev_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:12:49 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/16 17:12:49 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_valid_ev_char(char c, size_t index)
{
	int	is_valid;

	is_valid = 0;
	// if (!ft_isalnum(*sp->iter) && !ft_strchr("_?", *sp->iter))
	if (!ft_isalnum(c) && !ft_strchr("_?", c))
		is_valid = 1;
	// if (*sp->iter == '?' && sp->iter > sp->last_found + 1)
	if (c == '?' && index > 0)
		is_valid = 1;
	return (is_valid);
}
