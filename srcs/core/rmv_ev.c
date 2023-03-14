/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmv_ev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:41:08 by fgastal-          #+#    #+#             */
/*   Updated: 2023/03/12 16:34:46 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static int	cmp_name(void *cont1, void *cont2)
{
	const char	*name1;
	const char	*name2;

	name1 = ((t_ev *)cont1)->name;
	name2 = (const char *) cont2;
	return (ft_strcmp(name1, name2) == 0);
}

/*
	The function rmv_ev removes an environment variable from
	g_core.ev_list by using ft_lst_find to find the node containing
	the variable and ft_lst_pop_node to remove the node.
*/
void	rmv_ev(const char *name)
{
	t_ftnode	*node;
	void		*ev;

	node = ft_lst_find(&(g_core.ev_list), (void *) name, cmp_name);
	if (node != NULL)
	{
		ev = ft_lst_pop_node(&(g_core.ev_list), node);
		clear_ev(ev);
		update_envp();
	}
}
