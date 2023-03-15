/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:37:39 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/13 19:32:34 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	print_exported_ev(void *content, size_t i, int isf, int isl);

/*
	The built-in "export" command allows exporting environment variables.
*/
int	builtin_export(t_cmd *cmd)
{
	char	**args;
	char	**slices;
	int		status;

	if (cmd->args_count == 1)
	{
		ft_lst_func_apply(&g_core.ev_list, print_exported_ev);
		return (ERR_SUCCESS);
	}
	status = ERR_SUCCESS;
	args = cmd->args + 1;
	while (*args != NULL)
	{
		slices = split_ev_line(*args);
		if (slices == NULL)
			status = not_a_valid_identifier_error();
		else if (slices != NULL)
		{
			set_ev(slices[0], slices[1]);
			free(slices);
		}
		args++;
	}
	return (status);
}

static void	print_exported_ev(void *content, size_t i, int isf, int isl)
{
	t_ev	*ev;

	(void) i;
	(void) isf;
	(void) isl;
	ev = (t_ev *) content;
	printf("declare -x %s=\"%s\"\n", ev->name, ev->value);
}
