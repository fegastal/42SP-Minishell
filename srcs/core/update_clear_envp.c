/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:35:09 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/13 14:35:09 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	update_envp(void)
{
	t_ftnode	*ev_iter;
	t_ev		*ev;
	char		**envp;
	char		**envp_iter;

	clear_envp();
	envp = malloc(sizeof(char *) * (g_core.ev_list.size + 1));
	envp_iter = envp;
	ev_iter = g_core.ev_list.front;
	while (ev_iter != NULL)
	{
		ev = (t_ev *) ev_iter->content;
		*envp_iter = ft_xstr_join("=", ev->name, ev->value);
		ev_iter = ev_iter->next;
		envp_iter++;
	}
	*envp_iter = NULL;
	g_core.envp = envp;
}

void	clear_envp(void)
{
	char	**envp_iter;

	if (g_core.envp == NULL)
		return ;
	envp_iter = g_core.envp;
	while (*envp_iter != NULL)
	{
		free(*envp_iter);
		*envp_iter = NULL;
		envp_iter++;
	}
	free(g_core.envp);
	g_core.envp = NULL;
}
