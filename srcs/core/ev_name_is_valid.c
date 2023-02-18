/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_name_is_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:27:56 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/12/27 12:27:56 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	ev_name_is_valid(char const *name)
{
	char const *iter;

	if (name == NULL)
		return (0);
	if (ft_isdigit(name[0]))
		return (0);
	iter = name;
	while (*iter != '\0')
	{
		if (!ft_isalnum(*iter) && *iter != '_')
			return (0);
		iter++;
	}
	return (1);
}
