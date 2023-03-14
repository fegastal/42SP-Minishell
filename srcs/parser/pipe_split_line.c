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

static void	default_mode(t_splitter *sp);

/*
	Takes a string containing a command or a sequence of commands
	separated by pipes and returns a list of slices of the string,
	where each slice represents a command.
*/
t_ftlist	pipe_split_line(const char *line)
{
	t_ftlist	list;

	list = parse_context(line, (t_context){
			.def_func = default_mode,
			.dquotes_func = NULL,
			.squotes_func = NULL,
			.end_func = NULL
		}, NULL, " ");
	return (list);
}

static void	default_mode(t_splitter *sp)
{
	char	*tmp;

	if (sp->last_found == NULL)
	{
		if (*sp->iter != '|')
			sp->last_found = sp->iter;
	}
	else if (sp->last_found != NULL)
	{
		if (*sp->iter == '|')
		{
			tmp = ft_strndup(sp->last_found, sp->iter - sp->last_found);
			ft_lst_push_back(&(sp->list), tmp);
			sp->last_found = NULL;
		}
	}
	if (*sp->iter == '"')
		sp->mode = DOUBLE_QUOTES;
	else if (*sp->iter == '\'')
		sp->mode = SINGLE_QUOTES;
}
