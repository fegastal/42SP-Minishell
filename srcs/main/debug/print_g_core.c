/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_g_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:44:01 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 17:44:01 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_g_core_fd(void);

void	print_g_core(const char *prefix)
{
	if (prefix != NULL)
		ft_putstr_fd((char *) prefix, 1);
	ft_putstr_fd("G_CORE:\n", 1);
	ft_putstr_fd("\tis_running: ", 1);
	ft_putnbr_fd(g_core.is_running, 1);
	ft_putstr_fd("\n\tcan_proceed: ", 1);
	ft_putnbr_fd(g_core.can_proceed, 1);
	ft_putstr_fd("\n\tlast_pid: ", 1);
	ft_putnbr_fd(g_core.last_pid, 1);
	ft_putstr_fd("\n\tlast_status: ", 1);
	ft_putnbr_fd(g_core.last_status, 1);
	ft_putstr_fd("\n\tpipe: [", 1);
	ft_putnbr_fd(g_core.pipe[0], 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd(g_core.pipe[1], 1);
	ft_putstr_fd("]\n", 1);
	print_g_core_fd();
}

static void	print_g_core_fd(void)
{
	ft_putstr_fd("\tstd_in: ", 1);
	ft_putnbr_fd(g_core.std_in, 1);
	ft_putstr_fd("\n\tstd_out: ", 1);
	ft_putnbr_fd(g_core.std_out, 1);
	ft_putstr_fd("\n\tfd_in: ", 1);
	ft_putnbr_fd(g_core.fd_in, 1);
	ft_putstr_fd(" (", 1);
	if (g_core.fd_in_type == FD_REDIR_FILE)
		ft_putstr_fd("FD_REDIR_FILE", 1);
	else if (g_core.fd_in_type == FD_REDIR_PIPE)
		ft_putstr_fd("FD_REDIR_PIPE", 1);
	else if (g_core.fd_in_type == FD_REDIR_STD)
		ft_putstr_fd("FD_REDIR_STD", 1);
	ft_putstr_fd(")\n\tfd_out: ", 1);
	ft_putnbr_fd(g_core.fd_out, 1);
	ft_putstr_fd(" (", 1);
	if (g_core.fd_out_type == FD_REDIR_FILE)
		ft_putstr_fd("FD_REDIR_FILE", 1);
	else if (g_core.fd_out_type == FD_REDIR_PIPE)
		ft_putstr_fd("FD_REDIR_PIPE", 1);
	else if (g_core.fd_out_type == FD_REDIR_STD)
		ft_putstr_fd("FD_REDIR_STD", 1);
	ft_putstr_fd(")\n", 1);
}
