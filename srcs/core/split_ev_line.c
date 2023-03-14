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

/*
	takes a line of text containing an environment variable and
	its value separated by an equal sign ("="). It splits
	this line into two parts, returning a pointer to a dynamically
	allocated array of two strings. The first string is the name
	of the variable and the second is the value associated with it.
*/
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
