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

/*
	The core_clear() function clears the dynamically allocated memory
	used during shell execution, including the list of environment
	variables, readline command history, and search paths.
*/
void	core_clear(void)
{
	clear_envp();
	ft_lst_clear(&(g_core.ev_list), clear_ev);
	clear_paths();
	rl_clear_history();
}
