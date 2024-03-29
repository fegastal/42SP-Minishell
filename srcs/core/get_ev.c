/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:27:56 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/12/27 12:27:56 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static int	cmp_name(void *node, void *name);

/*
	The function get_ev_value takes a string with the name of an
	environment variable and returns its value as a string,
	searching through a linked list of t_ev structures.
*/
char	*get_ev_value(const char *name)
{
	t_ev	*ev;

	ev = get_ev(name);
	if (ev == NULL)
		return (NULL);
	return (ft_strdup(ev->value));
}

/*
	Returns a pointer to a t_ev structure that contains
	information about an environment variable from its name.
*/
t_ev	*get_ev(const char *name)
{
	t_ftnode	*node;

	if (ft_lst_is_empty(&(g_core.ev_list)))
		return (NULL);
	node = ft_lst_find(&(g_core.ev_list), (void *) name, cmp_name);
	if (node == NULL)
		return (NULL);
	return (node->content);
}

static int	cmp_name(void *node, void *name)
{
	const char	*name1;
	const char	*name2;

	name1 = ((t_ev *) node)->name;
	name2 = (const char *) name;
	while (*name1 != '\0' && *name2 != '\0')
	{
		if (*name1 != *name2)
			return (0);
		name1++;
		name2++;
	}
	return (*name1 == *name2);
}
