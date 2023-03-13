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

#include "core.h"

void	core_clear(void)
{
	ft_putstr_fd("cleaning core!\n", 1);
	clear_envp();
	ft_lst_clear(&(g_core.ev_list), clear_ev);
	clear_paths();
	rl_clear_history();
}
