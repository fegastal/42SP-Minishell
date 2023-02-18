/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:21:42 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/01/26 19:21:42 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_slices(char **str, t_ftnode *node);
static void	clear_slice(void *slice);

char	*expand_line(char const *line)
{
	t_ftlist	sliced;
	t_ftnode	*iter;
	char		*str;
	char		*tmp;

	int			counter;

	sliced = slice_line(line);
	iter = sliced.front;
	counter = 0;
	str = ft_calloc(1, sizeof(char));
	while (iter != NULL)
	{
		tmp = join_slices(&str, iter);
		str = tmp;
		iter = iter->next;
		counter++;
	}
	ft_lst_clear(&sliced, clear_slice);
	return (str);
}

static char	*join_slices(char **str, t_ftnode *node)
{
	t_slice		*slice;
	t_ev_node	*ev;
	char		*tmp;
	char		*result;

	slice = node->content;
	if (slice->type == SLICE_TYPE_NON_VAR)
		tmp = slice->start;
	else if (slice->type == SLICE_TYPE_VAR)
	{
		ev = get_ev(slice->start + 1);
		if (ev != NULL)
			tmp = ev->value;
		else
			tmp = "";
	}
	result = ft_xstr_join("", *str, tmp);
	free(*str);
	return (result);
}

static void	clear_slice(void *slice)
{
	free(((t_slice *) slice)->start);
	free((t_slice *) slice);
}
