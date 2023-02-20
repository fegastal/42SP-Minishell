/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_context.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:30:22 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/20 13:30:22 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// [PENDENTE]: Verificar se alguma função do context é NULL, caso seja, executar a função padrão.

t_ftlist	parse_context(const char *line, t_context context)
{
	t_splitter	splitter;

	ft_lst_init(&(splitter.list));
	splitter.mode = DEFAULT;
	splitter.last_found = NULL;
	splitter.iter = line;
	while (*splitter.iter != '\0')
	{
		if (splitter.mode == DEFAULT)
			context.def_func(&splitter);
		else if (splitter.mode == DOUBLE_QUOTES)
			context.dquotes_func(&splitter);
		else if (splitter.mode == SINGLE_QUOTES)
			context.squotes_func(&splitter);
		splitter.iter++;
	}
	context.end_func(&splitter);
	return (splitter.list);
}

static void	def_func(t_splitter *ps)
{
	if (ps->last_found == NULL)
		ps->last_found = ps->iter;
	if (*ps->iter == '"')
		ps->mode = DOUBLE_QUOTES;
	else if (*ps->iter == '\'')
		ps->mode = SINGLE_QUOTES;
}

static void	dquotes_func(t_splitter *sp)
{
	if (*sp->iter == '"')
		sp->mode = DEFAULT;
}

static void	squotes_func(t_splitter *sp)
{
	if (*sp->iter == '\'')
		sp->mode = DEFAULT;
}

static void	end_func(t_splitter *sp)
{
	if (splitter->last_found != NULL)
		ft_lst_push_back(&(splitter.list), ft_strdup(splitter.last_found));
}
