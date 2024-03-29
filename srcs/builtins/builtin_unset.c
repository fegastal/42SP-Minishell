/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:57:07 by fgastal-          #+#    #+#             */
/*   Updated: 2023/03/12 16:17:24 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/*
	The builtin_unset function is an internal
	shell command that removes one or more environment variables.
*/
int	builtin_unset(t_cmd *cmd)
{
	char	**iter;

	iter = cmd->args + 1;
	while (*iter != NULL)
	{
		rmv_ev(*iter);
		iter++;
	}
	return (0);
}
