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
// line:       echo "Path: $PATH" | expr $? + $? | echo 'oi'

#include "minishell.h"

// aux: VAR
// mode: DEFAULT
// last_found:      *
// line:       echo $PATH
// iter:            ^
// list:
// [
//  	(DEFAULT, "echo ")
// ]

static void	def_func(t_splitter *sp);
static void	dquotes_func(t_splitter *sp);
static void	end_func(t_splitter *sp);
static char	*join_slices(t_ftlist *slices);

char	*expand_line(const char *line)
{
	t_ftlist		slices;
	t_ftnode		*node;
	t_slice_type	last_type;
	char			*result;

	last_type = NON_VAR;
	slices = parse_context(line, (t_context) {
		.def_func = &def_func,
		.dquotes_func = &dquotes_func,
		.squotes_func = NULL,
		.end_func = &end_func
	}, &last_type);
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

static void	def_func(t_splitter *sp)
{
	t_slice_type	*last_type;
	t_slice			*slice;

	last_type = (t_slice_type *) sp->aux;
	if (*last_type == VAR)
	{
		if (!ft_isalnum(*sp->iter) && *sp->iter != '?')
		{
			slice = malloc(sizeof(t_slice));
			slice->start = ft_strndup(sp->last_found, sp->iter - sp->last_found);
			slice->type = *last_type;
			ft_lst_push_back(&sp->list, slice);
			sp->last_found = sp->iter;
			*last_type = NON_VAR;
		}
		if (*sp->iter == '"')
			sp->mode = DOUBLE_QUOTES;
		else if (*sp->iter == '\'')
			sp->mode = SINGLE_QUOTES;
		else if (*sp->iter == '$')
		{
			slice = malloc(sizeof(t_slice));
			slice->start = ft_strndup(sp->last_found, sp->iter - sp->last_found);
			slice->type = *last_type;
			ft_lst_push_back(&sp->list, slice);
			sp->last_found = sp->iter;
			*last_type = VAR;
		}
	}
	else if (*last_type == NON_VAR)
	{
		if (sp->last_found == NULL && !ft_strchr("\"'$", *sp->iter))
			sp->last_found = sp->iter;
		else if (*sp->iter == '$')
		{
			slice = malloc(sizeof(t_slice));
			slice->start = ft_strndup(sp->last_found, sp->iter - sp->last_found);
			slice->type = *last_type;
			ft_lst_push_back(&sp->list, slice);
			sp->last_found = sp->iter;
			*last_type = VAR;
		}
		else if (*sp->iter == '"')
			sp->mode = DOUBLE_QUOTES;
		else if (*sp->iter == '\'')
			sp->mode = SINGLE_QUOTES;
	}
}

static void	dquotes_func(t_splitter *sp)
{
	t_slice_type	*last_type;
	t_slice			*slice;

	last_type = (t_slice_type *) sp->aux;
	if (*last_type == VAR)
	{
		if (!ft_isalnum(*sp->iter) && *sp->iter != '?')
		{
			slice = malloc(sizeof(t_slice));
			slice->start = ft_strndup(sp->last_found, sp->iter - sp->last_found);
			slice->type = *last_type;
			ft_lst_push_back(&sp->list, slice);
			sp->last_found = sp->iter;
			*last_type = NON_VAR;
		}
		if (*sp->iter == '"')
			sp->mode = DEFAULT;
	}
	else if (*last_type == NON_VAR)
	{
		if (*sp->iter == '$')
		{
			slice = malloc(sizeof(t_slice));
			slice->start = ft_strndup(sp->last_found, sp->iter - sp->last_found);
			slice->type = *last_type;
			ft_lst_push_back(&sp->list, slice);
			sp->last_found = sp->iter;
			*last_type = VAR;
		}
		else if (*sp->iter == '"')
			sp->mode = DEFAULT;
	}
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
		tmp = ft_strdup(slice->start);
		if (slice->type == VAR && ft_strlen(slice->start) > 1)
		{
			if (slice->start[1] == '?')
			{
				ft_xstr_supplant(&tmp, ft_itoa(g_core.last_status));
				ft_xstr_supplant(&tmp, ft_xstr_append(tmp, slice->start + 2));
			}
			else
				ft_xstr_supplant(&tmp, get_ev_value(slice->start + 1));
		}
		ft_xstr_supplant(&result, ft_xstr_append(result, tmp));
		free(tmp);
		node = node->next;
	}
	return (result);
}

// static void	def_func(t_splitter *sp)
// {
// 	t_slice_type	*last_type;
// 	t_slice			*slice;

// 	last_type = (t_slice_type *) sp->aux;
// 	if (*last_type == VAR)
// 	{
// 		if (!ft_isalnum(*sp->iter) && *sp->iter != '?')
// 		{
// 			slice = malloc(sizeof(t_slice));
// 			slice->start = ft_strndup(sp->last_found, sp->iter - sp->last_found);
// 			slice->type = *last_type;
// 			ft_lst_push_back(&sp->list, slice);
// 			sp->last_found = sp->iter;
// 			*last_type = NON_VAR;
// 		}
// 		if (*sp->iter == '"')
// 			sp->mode = DOUBLE_QUOTES;
// 		else if (*sp->iter == '\'')
// 			sp->mode = SINGLE_QUOTES;
// 		else if (*sp->iter == '$')
// 		{
// 			slice = malloc(sizeof(t_slice));
// 			slice->start = ft_strndup(sp->last_found, sp->iter - sp->last_found);
// 			slice->type = *last_type;
// 			ft_lst_push_back(&sp->list, slice);
// 			sp->last_found = sp->iter;
// 			*last_type = VAR;
// 		}
// 	}
// 	else if (*last_type == NON_VAR)
// 	{
// 		if (sp->last_found == NULL && !ft_strchr("\"'$", *sp->iter))
// 			sp->last_found = sp->iter;
// 		else if (*sp->iter == '$')
// 		{
// 			slice = malloc(sizeof(t_slice));
// 			slice->start = ft_strndup(sp->last_found, sp->iter - sp->last_found);
// 			slice->type = *last_type;
// 			ft_lst_push_back(&sp->list, slice);
// 			sp->last_found = sp->iter;
// 			*last_type = VAR;
// 		}
// 		else if (*sp->iter == '"')
// 			sp->mode = DOUBLE_QUOTES;
// 		else if (*sp->iter == '\'')
// 			sp->mode = SINGLE_QUOTES;
// 	}
// }

// static void	dquotes_func(t_splitter *sp)
// {
// 	t_slice_type	*last_type;
// 	t_slice			*slice;

// 	last_type = (t_slice_type *) sp->aux;
// 	if (*last_type == VAR)
// 	{
// 		if (!ft_isalnum(*sp->iter) && *sp->iter != '?')
// 		{
// 			slice = malloc(sizeof(t_slice));
// 			slice->start = ft_strndup(sp->last_found, sp->iter - sp->last_found);
// 			slice->type = *last_type;
// 			ft_lst_push_back(&sp->list, slice);
// 			sp->last_found = sp->iter;
// 			*last_type = NON_VAR;
// 		}
// 		if (*sp->iter == '"')
// 			sp->mode = DEFAULT;
// 	}
// 	else if (*last_type == NON_VAR)
// 	{
// 		if (*sp->iter == '$')
// 		{
// 			slice = malloc(sizeof(t_slice));
// 			slice->start = ft_strndup(sp->last_found, sp->iter - sp->last_found);
// 			slice->type = *last_type;
// 			ft_lst_push_back(&sp->list, slice);
// 			sp->last_found = sp->iter;
// 			*last_type = VAR;
// 		}
// 		else if (*sp->iter == '"')
// 			sp->mode = DEFAULT;
// 	}
// }

// static void	end_func(t_splitter *sp)
// {
// 	t_slice_type	*last_type;
// 	t_slice			*slice;

// 	last_type = (t_slice_type *) sp->aux;
// 	if (sp->last_found != NULL)
// 	{
// 		slice = malloc(sizeof(t_slice));
// 		slice->start = ft_strdup(sp->last_found);
// 		slice->type = *last_type;
// 		ft_lst_push_back(&sp->list, slice);
// 		sp->last_found = NULL;
// 	}
// }

// static char	*join_slices(t_ftlist *slices)
// {
// 	t_ftnode	*node;
// 	t_slice		*slice;
// 	char		*result;
// 	char		*tmp;

// 	result = NULL;
// 	node = slices->front;
// 	while (node != NULL)
// 	{
// 		slice = (t_slice *) node->content;
// 		ft_putstr_fd("Slice: (", 1);
// 		ft_putstr_fd(slice->start, 1);
// 		ft_putstr_fd(")\n", 1);
// 		if (slice->type == NON_VAR)
// 			ft_xstr_supplant(&result, ft_xstr_append(result, slice->start));
// 		else if (slice->type == VAR)
// 		{
// 			if (ft_strlen(slice->start) == 1)
// 				ft_xstr_supplant(&result, ft_xstr_append(result, slice->start));
// 			else if (slice->start[1] == '?')
// 			{
// 				ft_putstr_fd("Entrou!\n", 1);
// 				tmp = ft_itoa(g_core.last_status);
// 				ft_xstr_supplant(&tmp, ft_xstr_append(tmp, slice->start + 2));
// 				ft_xstr_supplant(&result, ft_xstr_append(result, tmp));
// 				free(tmp);
// 			}
// 			else
// 			{
// 				ft_xstr_supplant(&result,
// 					ft_xstr_append(result, get_ev_value(slice->start + 1)));
// 			}
// 		}
// 		free(slice->start);
// 		node = node->next;
// 	}
// 	return (result);
// }












































// TESTES DE MESA

// last_type:	NON_VAR
// mode:		DEFAULT
// last_found:	                    *
// line: 		echo $NAME "oi $NAME !"
// iter: 		                       ^
/* list:
	[
		(NON_VAR, "echo "),
		(VAR, "$NAME"),
		(NON_VAR, " \"oi "),
		(VAR, "$NAME"),
		(NON_VAR, " !\"")
		↑
	]
*/

// result = "echo DESKTOP-2QJQV7S \"oi DESKTOP-2QJQV7S !\""
// slice = (NON_VAR, " !\"")
// tmp = "echo DESKTOP-2QJQV7S \"oi DESKTOP-2QJQV7S !\""

// typedef enum	e_slice_type
// {
// 	NON_VAR = 0,
// 	VAR = 1
// }	t_slice_type;
// typedef struct	s_slice
// {
// 	char			*start;
// 	t_slice_type	type;
// }	t_slice;
// typedef struct	s_context
// {
// 	void	(*def_func)(t_splitter *);
// 	void	(*dquotes_func)(t_splitter *);
// 	void	(*squotes_func)(t_splitter *);
// 	void	(*end_func)(t_splitter *);
// }	t_context;
// typedef struct	s_splitter
// {
// 	char const	*line;
// 	char const	*iter;
// 	char const	*last_found;
// 	t_ftlist	list;
// 	t_mode		mode;
// 	void		*aux;
// }	t_splitter;
// typedef enum	e_mode
// {
// 	DEFAULT,
// 	DOUBLE_QUOTES,
// 	SINGLE_QUOTES
// }	t_mode;




















// // Last_type deve iniciar com valor de NON_VAR
// static void	def_func(t_splitter *sp)
// {
// 	char			*tmp;
// 	t_slice			*slice;
// 	t_slice_type	*last_type;

// 	last_type = (t_slice_type *) sp->aux;
// 	if (*sp->iter != '$')
// 	{
// 		if (sp->last_found == NULL)
// 			sp->last_found = sp->iter;
// 	}
// 	else if (*sp->iter == '"')
// 		sp->mode = DOUBLE_QUOTES;
// 	else
// 	{
// 		tmp = ft_strndup(sp->last_found, sp->iter - sp->last_found);
// 		slice = malloc(sizeof(t_slice));
// 		slice->start = tmp;
// 		slice->type = *last_type;
// 		ft_lst_push_back(&sp->list, slice);
// 		sp->last_found = NULL;
// 		*last_type = VAR;
// 	}
// }

// static void	dquotes_func(t_splitter *sp)
// {
// 	if (*sp->iter == '"')
// 		sp->mode = DEFAULT;
// }

// static void	end_func(t_splitter *sp)
// {
// 	char			*tmp;
// 	t_slice			*slice;
// 	t_slice_type	*last_type;

// 	last_type = (t_slice_type *) sp->aux;
// 	if (sp->last_found != NULL)
// 	{
// 		tmp = ft_strdup(sp->last_found);
// 		slice = malloc(sizeof(t_slice));
// 		slice->start = tmp;
// 		slice->type = *last_type;
// 	}
// }








































// echo $NAME "oi $NAME"
// ^    ^    ^    ^    ^
// N    V    N    V    N


// static char	*join_slices(char **str, t_ftnode *node);
// static void	clear_slice(void *slice);

// char	*expand_line(const char *line)
// {
// 	t_ftlist	sliced;
// 	t_ftnode	*iter;
// 	char		*str;
// 	char		*tmp;

// 	sliced = slice_line(line);
// 	iter = sliced.front;
// 	str = ft_calloc(1, sizeof(char));
// 	while (iter != NULL)
// 	{
// 		tmp = join_slices(&str, iter);
// 		str = tmp;
// 		iter = iter->next;
// 	}
// 	ft_lst_clear(&sliced, clear_slice);
// 	return (str);
// }

// static char	*join_slices(char **str, t_ftnode *node)
// {
// 	t_slice		*slice;
// 	t_ev		*ev;
// 	char		*tmp;
// 	char		*tmp2;
// 	char		*result;

// 	slice = node->content;
// 	if (slice->type == SLICE_TYPE_NON_VAR)
// 		tmp = ft_strdup(slice->start);
// 	else if (slice->type == SLICE_TYPE_VAR)
// 	{
// 		if (slice->start[1] == '?')
// 		{
// 			tmp2 = ft_itoa(g_core.last_status);
// 			tmp = ft_xstr_append(tmp2, slice->start + 2);
// 			free(tmp2);
// 		}
// 		else if (ft_strchr(" \0\"'|<>", slice->start[1]))
// 			tmp = ft_strdup(slice->start);
// 		else	// Condicional que trata da substituição de variáveis de ambiente
// 		{
// 			ev = get_ev(slice->start + 1);
// 			if (ev != NULL)
// 				tmp = ft_strdup(ev->value);
// 			else
// 				tmp = ft_strdup("");
// 		}
// 	}
// 	result = ft_xstr_append(*str, tmp);
// 	free(*str);
// 	free(tmp);
// 	return (result);
// }

// static void	clear_slice(void *slice)
// {
// 	free(((t_slice *) slice)->start);
// 	free((t_slice *) slice);
// }
