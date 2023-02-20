/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:26:18 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/20 12:26:18 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_split(void *content, size_t i, int _if, int _il)
{
	printf("%lu) \"%s\"\n", i, (char *) content);
	_if = _if;
	_il = _il;
}

void	exec_line(const char *line)
{
	t_ftlist	pipe_list;

	pipe_list = pipe_split_line(line);
	ft_lst_func_apply(&pipe_list, print_split);
	ft_lst_clear(&pipe_list, free);
}
