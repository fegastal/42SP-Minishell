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
	set_ev("FILES", "file1.c file2.c file3.c", IS_NOT_EXPORT);
	set_ev("NAME", "nomezin", IS_NOT_EXPORT);
	set_ev("MSG", "Uma mensagem muito legal", IS_NOT_EXPORT);
}
