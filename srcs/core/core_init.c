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

static char	*get_path_ev(char *envp[]);

void	core_init(int argc, char *argv[], char *envp[])
{
	char	*path_value;

	ft_lst_init(&(g_core.ev_list));
	path_value = get_path_ev(envp);
	set_ev(ft_strdup("PATH"), path_value);
	// free(path_value);

	// Temporário
	set_ev(ft_strdup("FILES"), ft_strdup("file1.c file2.c file3.c"));
	set_ev(ft_strdup("NAME"), ft_strdup("nomezin"));
	set_ev(ft_strdup("MSG"), ft_strdup("Uma mensagem muito legal"));
	// ----------

	g_core.last_pid = -1;
	g_core.last_status = 0;
	g_core.argc = argc;
	g_core.argv = argv;
	g_core.envp = envp;
	g_core.paths = ft_split(path_value, ':');
}

static char	*get_path_ev(char *envp[])
{
	char	*tmp;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_strdup(envp[i] + 5);
			return (tmp);
		}
		i += 1;
	}
	return (NULL);
}
