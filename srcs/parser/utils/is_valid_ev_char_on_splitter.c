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

int	is_valid_ev_char_on_splitter(t_splitter *sp)
{
	int		is_valid;
	char	c;
	char	first_char;
	size_t	index;

	is_valid = 0;
	c = *sp->iter;
	first_char = *(sp->last_found + 1);
	index = sp->iter - sp->last_found;
	if ((ft_isalnum(c) || c == '_') && first_char != '?')
		is_valid = 1;
	if (c == '?' && index == 1)
		is_valid = 1;
	return (is_valid);
}
