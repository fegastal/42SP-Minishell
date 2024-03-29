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

static char	**split_with_delim(const char *line, const char *delim);
static char	**split_with_no_delim(const char *line);

/*
	takes a line of text containing an environment variable and
	its value separated by an equal sign ("="). It splits
	this line into two parts, returning a pointer to a dynamically
	allocated array of two strings. The first string is the name
	of the variable and the second is the value associated with it.
*/
char	**split_ev_line(const char *line)
{
	const char	*delim;
	char		**slices;

	delim = ft_strchr(line, '=');
	if (delim != NULL)
		slices = split_with_delim(line, delim);
	else
		slices = split_with_no_delim(line);
	return (slices);
}

static char	**split_with_delim(const char *line, const char *delim)
{
	char	**slices;
	char	*name;
	char	*value;

	slices = malloc(sizeof(char *) * 2);
	name = ft_strndup(line, delim - line);
	if (!ev_name_is_valid(name))
	{
		free(name);
		free(slices);
		return (NULL);
	}
	value = get_str_no_quotes(delim + 1);
	slices[0] = name;
	slices[1] = value;
	return (slices);
}

static char	**split_with_no_delim(const char *line)
{
	char	**slices;
	char	*name;

	if (!ev_name_is_valid(line))
		return (NULL);
	slices = malloc(sizeof(char *) * 2);
	name = ft_strdup(line);
	slices[0] = name;
	slices[1] = NULL;
	return (slices);
}
