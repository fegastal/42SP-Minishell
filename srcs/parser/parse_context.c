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

static void	def_func(t_splitter *ps, t_context *context);
static void	dquotes_func(t_splitter *sp, t_context *context);
static void	squotes_func(t_splitter *sp, t_context *context);
static void	end_func(t_splitter *sp, t_context *context);

/*
	Aux is an optional parameter, it is an auxiliar variable to use inside mode
	functions. Pass NULL if you don't need it.
*/
t_ftlist	parse_context(const char *line, t_context context, void *aux)
{
	t_splitter	splitter;

	ft_lst_init(&(splitter.list));
	splitter.mode = DEFAULT;
	splitter.last_found = line;
	// splitter.last_found = NULL;
	splitter.iter = line;
	splitter.line = line;
	splitter.aux = aux;
	while (*splitter.iter != '\0')
	{
		if (splitter.mode == DEFAULT)
			def_func(&splitter, &context);
		else if (splitter.mode == DOUBLE_QUOTES)
			dquotes_func(&splitter, &context);
		else if (splitter.mode == SINGLE_QUOTES)
			squotes_func(&splitter, &context);
		splitter.iter++;
	}
	end_func(&splitter, &context);
	return (splitter.list);
}

static void	def_func(t_splitter *sp, t_context *context)
{
	if (context->def_func != NULL)
		return ((void) context->def_func(sp));
	else
	{
		if (sp->last_found == NULL)
			sp->last_found = sp->iter;
		if (*sp->iter == '"')
			sp->mode = DOUBLE_QUOTES;
		else if (*sp->iter == '\'')
			sp->mode = SINGLE_QUOTES;
	}
}

static void	dquotes_func(t_splitter *sp, t_context *context)
{
	if (context->dquotes_func != NULL)
		return ((void) context->dquotes_func(sp));
	else
	{
		if (*sp->iter == '"')
			sp->mode = DEFAULT;
	}
}

static void	squotes_func(t_splitter *sp, t_context *context)
{
	if (context->squotes_func != NULL)
		return ((void) context->squotes_func(sp));
	else
	{
		if (*sp->iter == '\'')
			sp->mode = DEFAULT;
	}
}

static void	end_func(t_splitter *sp, t_context *context)
{
	if (context->end_func != NULL)
		return ((void) context->end_func(sp));
	else
	{
		if (sp->last_found != NULL)
			ft_lst_push_back(&(sp->list), ft_strdup(sp->last_found));
	}
}
