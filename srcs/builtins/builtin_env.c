/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:13:33 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/13 19:33:11 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	print_ev(void *content, size_t i, int first, int last);

/*
	The builtin_env function prints all defined
	environment variables on the screen.
*/
int	builtin_env(t_cmd *cmd)
{
	if (cmd->args_count != 1)
	{
		error(ERR_CUSTOM_ERROR, "Error: Too many arguments!\n");
		return (ERR_WRONG_BUILTIN_ARGS);
	}
	ft_lst_func_apply(&g_core.ev_list, print_ev);
	return (0);
}

static void	print_ev(void *content, size_t i, int first, int last)
{
	t_ev	*ev;

	(void) i;
	(void) first;
	(void) last;
	ev = (t_ev *) content;
	printf("%s=%s\n", ev->name, ev->value);
}
