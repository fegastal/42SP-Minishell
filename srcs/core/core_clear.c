/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:11:16 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/09 11:11:16 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	core_clear(void)
{
	char	**iter;

	ft_lst_clear(&(g_core.ev_list), clear_ev);
	iter = g_core.paths;
	while (*iter != NULL)
	{
		free(*iter);
		iter++;
	}
	free(g_core.paths);
}
