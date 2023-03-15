/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:39:02 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 16:26:11 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_screen(void)
{
	printf("\e[1;1H\e[2J");
}

char	*get_prefix(void)
{
	return ("42Minishell$ ");
}
