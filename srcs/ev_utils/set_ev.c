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

#include "minishell.h"

static int	lesser_func(void *node, void *new_node)
{
	char	*name1;
	char	*name2;

	name1 = ((t_ev_node *) node)->name;
	name2 = ((t_ev_node *) new_node)->name;
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
int	set_ev(const char *name, const char *value, int is_export)
{
	t_ev_node	*node;
	int			ev_code;

	node = get_ev(name);
	if (node == NULL)
	{
		ev_code = EV_PUSH;
		node = malloc(sizeof(t_ev_node));
		if (node == NULL)
			return (EV_ERROR);
		node->is_export = 0;
	}
	else
		ev_code = EV_UPDATE;
	node->name = name;
	node->value = value;
	if (is_export == 0 || is_export == 1)
		node->is_export = is_export;
	if (ev_code == EV_PUSH)
		ft_lst_push_ord(&(g_core.ev_list), node, lesser_func);
	return (ev_code);
}
