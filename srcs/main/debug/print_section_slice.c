/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_section_slice.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:00:02 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 17:00:02 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_section_slice(t_section_slice *slice, const char *prefix)
{
	if (slice == NULL)
		return ;
	if (prefix != NULL)
		ft_putstr_fd((char *) prefix, 1);
	ft_putstr_fd("Slice: (", 1);
	if (slice->type == REDIR_IN)
		ft_putstr_fd("REDIR_IN", 1);
	else if (slice->type == REDIR_OUT)
		ft_putstr_fd("REDIR_OUT", 1);
	else if (slice->type == REDIR_APPEND)
		ft_putstr_fd("REDIR_OUT", 1);
	else if (slice->type == REDIR_HEREDOC)
		ft_putstr_fd("REDIR_HEREDOC", 1);
	else if (slice->type == REDIR_NONE)
		ft_putstr_fd("REDIR_NONE", 1);
	else if (slice->type == REDIR_CMD)
		ft_putstr_fd("REDIR_CMD", 1);
	ft_putstr_fd(", \"", 1);
	ft_putstr_fd(slice->str, 1);
	ft_putstr_fd("\", fd=[", 1);
	ft_putnbr_fd(slice->fd, 1);
	ft_putstr_fd("])\n", 1);
}
