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

void	print_cmd(t_cmd *cmd, int fd)
{
	char	**tmp;

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
	// printf("{\n  path: %s,\n  args: [", cmd->path);
	tmp = cmd->args;
	while (*tmp != NULL)
	{
		ft_putstr_fd("\n    \"", fd);
		ft_putstr_fd(*tmp, fd);
		ft_putstr_fd("\"", fd);
		// printf("\n    %s", *tmp);
		if (*(tmp + 1) != NULL)
			ft_putstr_fd(",", fd);
			// printf(",");
		else
			ft_putstr_fd("\n  ", fd);
			// printf("\n  ");
		tmp++;
	}
	ft_putstr_fd("],\n  args_count: ", fd);
	ft_putnbr_fd(cmd->args_count, fd);
	ft_putstr_fd("\n  is_builtin: ", fd);
	ft_putnbr_fd(cmd->is_builtin, fd);
	ft_putstr_fd("\n}\n", fd);
	// printf("]\nargs_count: %d\n}\n", cmd->args_count);
}
