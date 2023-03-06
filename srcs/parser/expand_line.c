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

char	*expand_line(const char *line)
{
	t_ftlist	sliced;
	t_ftnode	*iter;
	char		*str;
	char		*tmp;

	sliced = slice_line(line);
	iter = sliced.front;
	str = ft_calloc(1, sizeof(char));
	while (iter != NULL)
	{
		tmp = join_slices(&str, iter);
		str = tmp;
		iter = iter->next;
	}
	ft_lst_clear(&sliced, clear_slice);
	return (str);
}

static char	*join_slices(char **str, t_ftnode *node)
{
	t_slice		*slice;
	t_ev		*ev;
	char		*tmp;
	char		*tmp2;
	char		*result;

	slice = node->content;
	if (slice->type == SLICE_TYPE_NON_VAR)
		tmp = ft_strdup(slice->start);
	else if (slice->type == SLICE_TYPE_VAR)
	{
		if (slice->start[1] == '?')
		{
			tmp2 = ft_itoa(g_core.last_status);
			tmp = ft_xstr_append(tmp2, slice->start + 2);
			free(tmp2);
		}
		else
		{
			ev = get_ev(slice->start + 1);
			if (ev != NULL)
				tmp = ft_strdup(ev->value);
			else
				tmp = ft_strdup("");
		}
	}
	result = ft_xstr_append(*str, tmp);
	free(*str);
	free(tmp);
	return (result);
}

static void	clear_slice(void *slice)
{
	free(((t_slice *) slice)->start);
	free((t_slice *) slice);
}
