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

void	core_init(void)
{
	ft_lst_init(&(g_core.ev_list));

	// Temporário
	set_ev("TEST3", "Value3", 0);
	set_ev("TEST2", "Value2", 0);
	set_ev("TEST", "Value", 0);
	set_ev("TES", "Valu", 0);
	set_ev("TEST1", "Value1", 0);
}
