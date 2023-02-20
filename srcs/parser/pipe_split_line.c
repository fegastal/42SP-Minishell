/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:57:33 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/20 09:57:33 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	default_mode(t_splitter *ps);
static void	double_quote_mode(t_splitter *ps);
static void	single_quote_mode(t_splitter *ps);
static void	end_func(t_splitter *ps);

t_ftlist	pipe_split_line(const char *line)
{
	t_ftlist	list;

	list = parse_context(line, (t_context){
			.def_func = default_mode,
			.dquotes_func = double_quote_mode,
			.squotes_func = single_quote_mode,
			.end_func = end_func
		});
	return (list);
}

static void	default_mode(t_splitter *ps)
{
	char	*tmp;

	if (ps->last_found == NULL)
	{
		if (*ps->iter != '|')
			ps->last_found = ps->iter;
	}
	else if (ps->last_found != NULL)
	{
		if (*ps->iter == '|')
		{
			tmp = ft_strndup(ps->last_found, ps->iter - ps->last_found);
			ft_lst_push_back(&(ps->list), tmp);
			ps->last_found = NULL;
		}
	}
	if (*ps->iter == '"')
		ps->mode = DOUBLE_QUOTES;
	else if (*ps->iter == '\'')
		ps->mode = SINGLE_QUOTES;
}

static void	double_quote_mode(t_splitter *ps)
{
	if (*ps->iter == '"')
		ps->mode = DEFAULT;
}

static void	single_quote_mode(t_splitter *ps)
{
	if (*ps->iter == '\'')
		ps->mode = DEFAULT;
}

static void	end_func(t_splitter *ps)
{
	if (splitter->last_found != NULL)
		ft_lst_push_back(&(splitter.list), ft_strdup(splitter.last_found));
}
