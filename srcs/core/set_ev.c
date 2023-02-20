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

static int	lesser_func(void *node, void *new_node)
{
	const char	*name1;
	const char	*name2;

	name1 = ((t_ev *) node)->name;
	name2 = ((t_ev *) new_node)->name;
	while (*name1 != '\0' && *name2 != '\0')
	{
		if (*name1 != *name2)
			break ;
		name1++;
		name2++;
	}
	return (*name1 < *name2);
}

/* SET_EV() Return values:
	> EV_ERROR	-> Allocation failed
	> EV_PUSH	-> Name doesn't exist. New Node is created
	> EV_UPDATE	-> Name exist. Existing Node is updated with value and is_export
		* If is_export is not 0 or 1, existing value will be kept
 */
t_ev_status	set_ev(const char *name, const char *value)
// int	set_ev(const char *name, const char *value, int is_export)
{
	t_ev_status	ev_code;
	t_ev		*node;

	node = get_ev(name);
	if (node == NULL)
	{
		ev_code = EV_PUSH;
		node = malloc(sizeof(t_ev));
		if (node == NULL)
			return (EV_ERROR);
	}
	else
	{
		free((char *) node->value);
		ev_code = EV_UPDATE;
	}
	// node->name = ft_strdup(name);
	// node->value = ft_strdup(value);
	node->value = value;
	if (ev_code == EV_PUSH)
	{
		node->name = name;
		ft_lst_push_ord(&(g_core.ev_list), node, lesser_func);
	}
	return (ev_code);
}
