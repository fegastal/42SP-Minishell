/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:57:07 by fgastal-          #+#    #+#             */
/*   Updated: 2023/03/12 16:19:16 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	builtin_exit(t_cmd *cmd)
{
	int	temp;

	if (cmd->args[1] == NULL)
		return (g_core.last_status);
	else if (cmd->args[2] == NULL)
	{
		if (ft_xstr_match_set(cmd->args[1], "0123456789+-"))
		{
			temp = ft_atoi(cmd->args[1]);
			return (temp);
		}
	}
	else
		return (1);	// Error too many arguments
	return (0);
}
