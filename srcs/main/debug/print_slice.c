/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_slice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:19:34 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/14 17:19:34 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_slice(t_slice *slice, const char *prefix)
{
	if (slice == NULL)
		return ;
	if (prefix != NULL)
		ft_putstr_fd((char *) prefix, 1);
	ft_putstr_fd("(type: ", 1);
	if (slice->type == VAR)
		ft_putstr_fd("VAR", 1);
	else
		ft_putstr_fd("NON_VAR", 1);
	ft_putstr_fd(", start: \"", 1);
	ft_putstr_fd(slice->start, 1);
	ft_putstr_fd("\")\n", 1);
}
