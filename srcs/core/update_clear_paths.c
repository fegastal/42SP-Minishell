/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clear_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:44:18 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/02 15:44:18 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

/*
	Frees the memory allocated for storing the system directories
	defined at the start of the shell.
*/
void	clear_paths(void)
{
	char	**iter;

	if (g_core.paths == NULL)
		return ;
	iter = g_core.paths;
	while (*iter != NULL)
	{
		free(*iter);
		iter++;
	}
	free(g_core.paths);
	g_core.paths = NULL;
}

/*
	Updates the variable "g_core.paths", which stores
	the paths where the shell looks for commands that the user types.
*/
void	update_paths(void)
{
	t_ev	*ev;
	char	**paths;

	clear_paths();
	ev = get_ev("PATH");
	if (ev == NULL)
		return ;
	paths = ft_split(ev->value, ':');
	g_core.paths = paths;
}
