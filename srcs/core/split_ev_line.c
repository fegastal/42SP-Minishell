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

static int	is_valid_name(const char *name);

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
		if (!is_valid_name(name))
		{
			free(name);
			free(slices);
			return (NULL);
		}
		value = ft_xstr_replace(delim + 1, "\"", NULL);
		slices[0] = name;
		slices[1] = value;
		return (slices);
	}
	else
		free(slices);
	return (NULL);
}

static int	is_valid_name(const char *name)
{
	const char	*iter;

	iter = name;
	if (ft_isdigit(*iter))
		return (0);
	while (*iter != '\0')
	{
		if (!ft_isalnum(*iter) && *iter != '_')
			return (0);
		iter++;
	}
	return (1);
}
