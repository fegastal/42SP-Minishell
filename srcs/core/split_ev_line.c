/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ev_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:54:19 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/19 17:54:19 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

char	**split_ev_line(const char *line)
{
	char	**slices;
	char	*name;
	char	*value;
	char	*delim;

	slices = malloc(sizeof(char *) * 2);
	delim = ft_strchr(line, '=');
	if (delim != NULL)
	{
		name = ft_strndup(line, delim - line);
		value = ft_xstr_replace(delim + 1, "\"", NULL);
		slices[0] = name;
		slices[1] = value;
		return (slices);
	}
	else
		free(slices);
	return (NULL);
}
