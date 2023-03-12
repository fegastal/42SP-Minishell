/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_name_is_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:27:56 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 16:35:45 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	ev_name_is_valid(const char *name)
{
	const char	*iter;

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
