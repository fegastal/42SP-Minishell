/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:26:05 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/09 12:26:05 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static void	print_args(char **args, int fd);

/*
	This function is used for debugging purposes. It prints the contents of a
	t_cmd struct to the given file descriptor.
*/
void	print_cmd(t_cmd *cmd, int fd)
{
	ft_putstr_fd("{\n  path: ", fd);
	if (cmd->path != NULL)
	{
		ft_putchar_fd('"', fd);
		ft_putstr_fd(cmd->path, fd);
		ft_putchar_fd('"', fd);
	}
	else
		ft_putstr_fd("NULL", fd);
	ft_putstr_fd(",\n  args: [", fd);
	print_args(cmd->args, fd);
	ft_putstr_fd("],\n  args_count: ", fd);
	ft_putnbr_fd(cmd->args_count, fd);
	ft_putstr_fd("\n  is_builtin: ", fd);
	ft_putnbr_fd(cmd->is_builtin, fd);
	ft_putstr_fd("\n}\n", fd);
}

static void	print_args(char **args, int fd)
{
	char	**tmp;

	tmp = args;
	while (*tmp != NULL)
	{
		ft_putstr_fd("\n    \"", fd);
		ft_putstr_fd(*tmp, fd);
		ft_putstr_fd("\"", fd);
		if (*(tmp + 1) != NULL)
			ft_putstr_fd(",", fd);
		else
			ft_putstr_fd("\n  ", fd);
		tmp++;
	}
}
