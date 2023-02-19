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

void	builtin_export(t_cmd *cmd)
{
	char	**args;
	// char	*delim;
	char	*name;
	char	*value;
	char	**slices;

	args = cmd->args + 1;
	while (*args != NULL)
	{
		slices = split_ev_line(*args);
		if (slices != NULL)
		{
			name = slices[0];
			value = slices[1];
			set_ev(name, value);
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
}
