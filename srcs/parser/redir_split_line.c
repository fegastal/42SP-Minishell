/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_split_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:47:12 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/20 14:47:12 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	default_mode(t_splitter *sp);
static void	double_quote_mode(t_splitter *sp);
static void	single_quote_mode(t_splitter *sp);
static void	end_func(t_splitter *sp);

t_ftlist	redir_split_line(const char *line)
{
	t_ftlist	redirs;

	redirs = parse_context(line, (t_context){
			.def_func = default_mode,
			.dquotes_func = double_quote_mode,
			.squotes_func = single_quote_mode,
			.end_func = end_func
		});
}

// Last found: // *
//             // wc < file1.txt
// Iter        // #
// mode = DEFAULT


static void	default_mode(t_splitter *sp)
{
	char	*tmp;
	t_slice	*slice;

	slice = malloc(sizeof(t_slice));
	slice->type = REDIR_NONE;
	if (*sp->iter == '"')
		sp->mode = DOUBLE_QUOTES;
	else if (*sp->iter == '\'')
		sp->mode = SINGLE_QUOTES;
	else if (*sp->iter == '<')
	{
		if (*(sp->iter + 1) == '<')
		{
			slice.type = REDIR_HEREDOC;
			sp->iter++;
		}
		else
			slice.type = REDIR_IN;
	}
	else if (*sp->iter == '>')
	{
		if (*(sp->iter + 1) == '>')
		{
			slice.type = REDIR_APPEND;
			sp->iter++;
		}
		else
			slice.type = REDIR_OUT;
	}
	if (slice->type == REDIR_NONE)
		free(slice);
	else
		ft_lst_push_back(&(sp.list), slice);
}

static void	double_quote_mode(t_splitter *sp)
{
	if (*sp->iter == '"')
		sp->mode = DEFAULT;
}

static void	single_quote_mode(t_splitter *sp)
{
	if (*sp->iter == '\'')
		sp->mode = DEFAULT;
}

static void	end_func(t_splitter *sp)
{
	if (splitter->last_found != NULL)
		ft_lst_push_back(&(splitter.list), ft_strdup(splitter.last_found));
}

