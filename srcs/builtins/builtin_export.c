/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:37:39 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/19 13:37:39 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	print_exported_ev(void *content, size_t i, int isf, int isl);

int	builtin_export(t_cmd *cmd)
{
	// char	*delim;
	// char	*name;
	// char	*value;
	char	**args;
	char	**slices;

	if (cmd->args_count == 1)
	{
		ft_lst_func_apply(&g_core.ev_list, print_exported_ev);
		return (ERR_NO_ERROR);
	}
	args = cmd->args + 1;
	while (*args != NULL)
	{
		slices = split_ev_line(*args);
		if (slices != NULL)
		{
			set_ev(slices[0], slices[1]);
			free(slices);
		}
		// delim = ft_strchr(*args, '=');
		// if (delim != NULL)
		// {
		// 	name = ft_strndup(*args, delim - *args);
		// 	value = ft_strtrim(delim + 1, "\"");
		// 	set_ev(name, value);
		// }
		args++;
	}
	return (ERR_NO_ERROR);
}

static void	print_exported_ev(void *content, size_t i, int isf, int isl)
{
	t_ev	*ev;

	ev = (t_ev *) content;
	printf("declare -x %s=\"%s\"\n", ev->name, ev->value);
	i = i;
	isf = isf;
	isl = isl;
}
