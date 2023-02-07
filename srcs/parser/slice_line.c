/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:21:16 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/01/26 12:21:16 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_slice	*new_slice(char *start, int is_var);
static void	check_mode_default(t_ftlist *slices, t_slicer *sl);
static void	check_mode_double_quotes(t_ftlist *slices, t_slicer *sl);
static t_ftlist	separate_slices(t_ftlist *slices);

// static void	print_node(void *content, size_t index, int is_first, int is_last)
// {
// 	t_slice	*slice;

// 	is_first = is_first;
// 	is_last = is_last;
// 	slice = content;
// 	if (slice->type == SLICE_TYPE_NON_VAR)
// 		printf("%lu) NON_VAR: {%s}\n", index, slice->start);
// 	else
// 		printf("%lu) VAR: {%s}\n", index, slice->start);
// }

t_ftlist	slice_line(char *line)
{
	t_ftlist	slices;
	t_ftlist	tmp;
	t_slicer	sl;

	sl.line = line;
	sl.chr = line;
	sl.tmp = line;
	sl.mode = SLCMODE_DEFAULT;
	sl.slice_type = SLICE_TYPE_NON_VAR;
	ft_lst_init(&tmp);
	ft_lst_push_back(&tmp, new_slice(line, SLICE_TYPE_NON_VAR));
	while (*(sl.chr) != '\0')
	{
		if (sl.mode == SLCMODE_DEFAULT)
			check_mode_default(&tmp, &sl);
		else if (sl.mode == SLCMODE_DOUBLE_QUOTES)
			check_mode_double_quotes(&tmp, &sl);
		else if (*(sl.chr) == '\'')
			sl.mode = SLCMODE_DEFAULT;
		sl.chr++;
	}
	slices = separate_slices(&tmp);
	ft_lst_clear(&tmp, free);
	return (slices);
}

static t_slice	*new_slice(char *start, int type)
{
	t_slice	*slice;

	slice = malloc(sizeof(t_slice));
	slice->start = start;
	slice->type = type;
	return (slice);
}

static void	check_mode_default(t_ftlist *slices, t_slicer *sl)
{
	char	c;
	int		slice_type;
	int		can_add_slice;

	c = *(sl->chr);
	slice_type = SLICE_TYPE_NON_VAR;
	if (c == '$')
		slice_type = SLICE_TYPE_VAR;
	else if (c == '"')
		sl->mode = SLCMODE_DOUBLE_QUOTES;
	else if (c == '\'')
		sl->mode = SLCMODE_QUOTES;
	can_add_slice = 0;
	if (sl->slice_type == SLICE_TYPE_NON_VAR)
		can_add_slice = (int)(ft_strchr("$\"'", c) != NULL);
	else if (sl->slice_type == SLICE_TYPE_VAR)
		can_add_slice = (int)(ft_strchr(" |$?'\"<>-", c) != NULL);
	if (can_add_slice)// && (slice_type ^ sl->slice_type))
	{
		sl->slice_type = slice_type;
		ft_lst_push_back(slices, new_slice(sl->chr, sl->slice_type));
		sl->tmp = sl->chr;
	}
}

static void	check_mode_double_quotes(t_ftlist *slices, t_slicer *sl)
{
	char	c;
	int		slice_type;
	int		can_add_slice;

	c = *(sl->chr);
	slice_type = SLICE_TYPE_NON_VAR;
	if (c == '$')
		slice_type = SLICE_TYPE_VAR;
	else if (c == '"')
		sl->mode = SLCMODE_DEFAULT;
	can_add_slice = 0;
	if (sl->slice_type == SLICE_TYPE_NON_VAR)
		can_add_slice = (int)(c == '$' || c == '"');
	else if (sl->slice_type == SLICE_TYPE_VAR)
		can_add_slice = (int)(ft_strchr(" |$?'\"<>-", c) != NULL);
	if (can_add_slice)// && (sl->slice_type ^ slice_type))
	{
		sl->slice_type = slice_type;
		ft_lst_push_back(slices, new_slice(sl->chr, sl->slice_type));
		sl->tmp = sl->chr;
	}
}

static t_ftlist	separate_slices(t_ftlist *slices)
{
	t_ftlist	list;
	t_ftnode	*node;
	t_slice		*tmp;
	char		*str1;
	char		*str2;

	ft_lst_init(&list);
	node = slices->front;
	while (node != NULL)
	{
		str1 = ((t_slice *)(node->content))->start;
		if (node->next != NULL)
		{
			str2 = ((t_slice *)(node->next->content))->start;
			tmp = new_slice(NULL, ((t_slice *)(node->content))->type);
			tmp->start = ft_strndup(str1, str2 - str1);
		}
		else if (node->next == NULL)
			tmp = new_slice(ft_strdup(str1), ((t_slice *)(node->content))->type);
		ft_lst_push_back(&list, tmp);
		node = node->next;
	}
	return (list);
}

// static void	check_mode_quotes(t_ftlist *slices, t_slicer *e)
// {
// 	char	c;

// 	c = *(e->chr);
// 	if (c == '\'')
// 		e->mode = SLCMODE_DEFAULT;
// }

// static void	check_mode_double_quote(t_ftlist *slices, t_slicer *e)
// {
// 	t_slice	*slice;
// 	char			c;

// 	c = *(e->chr);
// 	if (e->slice_type == SLICE_TYPE_NON_VAR)
// 	{
// 		if (c == '$')
// 		{
// 			t_lst_push_back(slices, new_slice(e->chr, SLICE_TYPE_VAR));
// 			e->slice_type = SLICE_TYPE_VAR;
// 		}
// 		else if (c == '"')
// 			e->mode = SLCMODE_DEFAULT;
// 	}
// 	else if (e->slice_type == SLICE_TYPE_VAR)
// 	{
// 		if (ft_strchr(" |$?'\"<>-", c) != NULL)
// 		{
// 			if (c == '"')
// 			{
// 				e->mode = SLCMODE_DEFAULT;
// 				t_lst_push_back(slices, new_slice(e->chr, SLICE_TYPE_NON_VAR));
// 				e->slice_type = SLICE_TYPE_NON_VAR;
// 				e->tmp = e->chr;
// 			}
// 			else if (c == '$')
// 			{
// 				t_lst_push_back(slices, new_slice(e->chr, SLICE_TYPE_VAR));
// 				e->slice_type = SLICE_TYPE_VAR;
// 				e->tmp = e->chr;
// 			}
// 			else
// 			{
// 				t_lst_push_back(slices, new_slice(e->chr, SLICE_TYPE_NON_VAR));
// 				e->slice_type = SLICE_TYPE_NON_VAR;
// 				e->tmp = e->chr;
// 			}
// 		}
// 	}
// }

// static void	check_mode_default(t_ftlist *slices, t_slicer *e)
// {
// 	t_slice	*slice;
// 	char			c;

// 	c = *(e->chr);
// 	if (e->slice_type == SLICE_TYPE_NON_VAR)
// 	{
// 		if (ft_strchr("$\"'", c) != NULL)
// 			e->tmp = e->chr;
// 		if (c == '$')
// 		{
// 			t_lst_push_back(slices, new_slice(e->chr, SLICE_TYPE_VAR));
// 			e->slice_type = SLICE_TYPE_VAR;
// 		}
// 		else if (c == '"')
// 		{
// 			t_lst_push_back(slices, new_slice(e->chr, SLICE_TYPE_NON_VAR));
// 			e->mode = SLCMODE_DOUBLE_QUOTES;
// 		}
// 		else if (c == '\'')
// 		{
// 			t_lst_push_back(slices, new_slice(e->chr, SLICE_TYPE_NON_VAR));
// 			e->mode = SLCMODE_QUOTES;
// 		}
// 	}
// 	else if (e->slice_type == SLICE_TYPE_VAR)
// 	{
// 		if (ft_strchr(" |$?'\"<>-", c) != NULL)
// 		{
// 			e->slice_type = SLICE_TYPE_NON_VAR;
// 			if (c == '$')
// 				e->slice_type = SLICE_TYPE_VAR;
// 			else if (c == '"')
// 				e->mode = SLCMODE_DOUBLE_QUOTES;
// 			else if (c == '\'')
// 				e->mode = SLCMODE_QUOTES;
// 			t_lst_push_back(slices, new_slice(e->chr, e->slice_type));
// 			e->tmp = e->chr;
// 		}
// 	}
// }

// static int	check_mode_default(t_ftlist **slices, t_slicer *e)
// {
// 	t_slice	*slice;
// 	char			c;

// 	c = *(e->chr);
// 	if (c == '$')
// 	{
// 		if (e->mode == SLCMODE_DEFAULT || e->mode == SLCMODE_DOUBLE_QUOTES)
// 		{
// 			if (!e->last_is_var)
// 				t_lst_push_back(slices[0], ft_strndup(e->tmp, e->chr - e->tmp));
// 			else
// 			{
// 				t_lst_push_back(slices[1], ft_strndup(e->tmp, e->chr - e->tmp));
// 				t_lst_push_back(slices[0], ft_strndup("", 1));
// 			}
// 			e->last_is_var = 1;
// 			e->tmp = e->chr;
// 		}
// 	}
// }