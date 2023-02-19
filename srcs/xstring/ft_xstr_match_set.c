/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstr_cmpset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:29:37 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/17 13:29:37 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xstring.h"

int	ft_xstr_match_set(const char *str, const char *set)
{
	const char	*iter;

	if (str == NULL || set == NULL)
		return (0);
	iter = str;
	while (*iter != '\0')
	{
		if (ft_strchr(set, *iter) == NULL)
			return (0);
		iter++;
	}
	return (1);
}
