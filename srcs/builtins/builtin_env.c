/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:13:33 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/19 18:13:33 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	print_ev(void *content, size_t i, int first, int last);

int	builtin_env(t_cmd *cmd)
{
	if (cmd->args_count != 1)
		return (1);
	ft_lst_func_apply(&g_core.ev_list, print_ev);
	return (0);
}

static void	print_ev(void *content, size_t i, int first, int last)
{
	t_ev	*ev;

	ev = (t_ev *) content;
	printf("%s=%s\n", ev->name, ev->value);
	i = i;
	first = first;
	last = last;
}
