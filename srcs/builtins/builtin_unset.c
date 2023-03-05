/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:57:07 by fgastal-          #+#    #+#             */
/*   Updated: 2023/02/17 11:31:29 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "builtins.h"

int	builtin_unset(t_cmd *cmd)
{
	char **iter;

	iter = cmd->args + 1;
	while (*iter != NULL)
	{
		rmv_ev(*iter);
		iter++;
	}
	return (0);
}
