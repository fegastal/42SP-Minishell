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

#include "minishell.h"

void	core_init(int argc, char *argv[], char *envp[])
{
	ft_lst_init(&(g_core.ev_list));
	g_core.argc = argc;
	g_core.argv = argv;
	g_core.envp = envp;
}
