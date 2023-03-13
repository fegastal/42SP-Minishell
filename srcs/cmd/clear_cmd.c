/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:46:00 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/16 09:46:00 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

/*
	The clear_cmd function releases the memory allocated
	to a command and its arguments.
*/
void	clear_cmd(t_cmd *cmd)
{
	char	**args;

	free(cmd->path);
	args = cmd->args;
	while (*args != NULL)
	{
		free(*args);
		args++;
	}
	free(cmd->args);
	free(cmd);
}
