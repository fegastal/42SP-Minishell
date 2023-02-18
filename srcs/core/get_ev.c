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

static int	cmp_name(void *node, void *name)
{
	char	*name1;
	char	*name2;

	name1 = ((t_ev_node *) node)->name;
	name2 = (char *) name;
	while (*name1 != '\0' && *name2 != '\0')
	{
		if (*name1 != *name2)
			return (0);
		name1++;
		name2++;
	}
	return (*name1 == *name2);
}

t_ev_node	*get_ev(const char *name)
{
	t_ftnode	*node;

	if (ft_lst_is_empty(&(g_core.ev_list)))
		return (NULL);
	node = ft_lst_find(&(g_core.ev_list), (void *) name, cmp_name);
	if (node == NULL)
		return (NULL);
	return (node->content);
}
