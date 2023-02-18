/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:57:07 by fgastal-          #+#    #+#             */
/*   Updated: 2023/02/17 11:31:29 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_exit(t_cmd *cmd)
{
	int temp;

	if (cmd->args[1] == NULL)
		exit(0);
	else if (cmd->args[2] == NULL)
	{
		if (ft_xstr_match_set(cmd->args[1], "0123456789+-"))
		{
			temp = ft_atoi(cmd->args[1]);
			exit(temp);
		}
	}
	else
	{
		printf("Too many arguments.\n");
		exit(1);
	}
}
