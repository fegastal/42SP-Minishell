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

#include "parser.h"

static void	parse_func(t_splitter *sp);
static void	end_func(t_splitter *sp);
static char	*join_slices(t_ftlist *slices);
static char	*get_slice_value(t_slice *slice);

/*
	Is responsible for parsing the user's input, expanding variables,
	expanding wildcards, and removing escape characters, before
	returning the expanded input to the caller.
*/
char	*expand_line(const char *line)
{
	t_ftlist		slices;
	t_ftnode		*node;
	t_slice_type	last_type;
	char			*result;

	if (ft_xstr_match_set(line, " \t"))
		return (NULL);
	last_type = NON_VAR;
	slices = parse_context(line, (t_context){
			.def_func = &parse_func,
			.dquotes_func = &parse_func,
			.squotes_func = NULL,
			.end_func = &end_func
		}, &last_type, NULL);
	result = join_slices(&slices);
	node = slices.front;
	while (node != NULL)
	{
		free(((t_slice *) node->content)->start);
		node = node->next;
	}
	ft_lst_clear(&slices, free);
	return (result);
}

static void	parse_func(t_splitter *sp)
{
	t_expander	e;

	e.last_type = (t_slice_type *) sp->aux;
	e.new_type = *e.last_type;
	e.can_add = 1;
	if (*sp->iter == '$')
		e.new_type = VAR;
	else if (*e.last_type == VAR && !is_valid_ev_char_on_splitter(sp))
		e.new_type = NON_VAR;
	else
		e.can_add = 0;
	if (*sp->iter == '"' && sp->mode == DEFAULT)
		sp->mode = DOUBLE_QUOTES;
	if (*sp->iter == '"' && sp->mode == DOUBLE_QUOTES)
		sp->mode = DEFAULT;
	else if (*sp->iter == '\'' && sp->mode == DEFAULT)
		sp->mode = SINGLE_QUOTES;
	if (!e.can_add)
		return ;
	e.slice = malloc(sizeof(t_slice));
	e.slice->start = ft_strndup(sp->last_found, sp->iter - sp->last_found);
	e.slice->type = *e.last_type;
	ft_lst_push_back(&sp->list, e.slice);
	sp->last_found = sp->iter;
	*e.last_type = e.new_type;
}

static void	end_func(t_splitter *sp)
{
	t_slice_type	*last_type;
	t_slice			*slice;

	last_type = (t_slice_type *) sp->aux;
	if (sp->last_found != NULL)
	{
		slice = malloc(sizeof(t_slice));
		slice->start = ft_strdup(sp->last_found);
		slice->type = *last_type;
		ft_lst_push_back(&sp->list, slice);
		sp->last_found = NULL;
	}
}

static char	*join_slices(t_ftlist *slices)
{
	t_ftnode		*node;
	t_slice			*slice;
	char			*result;
	char			*tmp;

	result = NULL;
	node = slices->front;
	while (node != NULL)
	{
		slice = (t_slice *) node->content;
		tmp = get_slice_value(slice);
		ft_xstr_supplant(&result, ft_xstr_append(result, tmp));
		free(tmp);
		node = node->next;
	}
	return (result);
}

static char	*get_slice_value(t_slice *slice)
{
	char	*result;

	result = NULL;
	if (slice->type == VAR && ft_strlen(slice->start) > 1)
	{
		if (slice->start[1] == '?')
		{
			result = ft_itoa(g_core.last_status);
			ft_xstr_supplant(&result, ft_xstr_append(result, slice->start + 2));
		}
		else
			result = get_ev_value(slice->start + 1);
	}
	else
		result = ft_strdup(slice->start);
	return (result);
}
