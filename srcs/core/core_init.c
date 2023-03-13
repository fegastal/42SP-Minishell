/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:25:16 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/12/27 12:25:16 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void	populate_ev_list(char *envp[]);

/*
	The function core_init initializes the g_core data structure with
	global variables used by the program. It initializes the list
	of environment variables, sets some global variables and
	updates the PATH and PWD environment variables.
*/
void	core_init(int argc, char *argv[], char *envp[])
{
	ft_lst_init(&(g_core.ev_list));
	populate_ev_list(envp);
	g_core.is_running = IS_RUNNING;
	g_core.std_in = dup(STDIN_FILENO);
	g_core.std_out = dup(STDOUT_FILENO);
	g_core.pipe[0] = 0;
	g_core.pipe[1] = 0;
	g_core.last_pid = -1;
	g_core.last_status = 0;
	g_core.argc = argc;
	g_core.argv = argv;
	// g_core.envp = envp;
	g_core.envp = NULL;
	update_envp();
	update_paths();
}

static void	populate_ev_list(char *envp[])
{
	char	**ev_line;
	char	**iter;

	iter = envp;
	while (*iter != NULL)
	{
		ev_line = split_ev_line(*iter);
		if (ev_line != NULL)
		{
			set_ev(ev_line[0], ev_line[1]);
			free(ev_line);
		}
		iter++;
	}
}
