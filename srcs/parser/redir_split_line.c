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
static void	end_func(t_splitter *sp);

t_ftlist	redir_split_line(const char *line)
{
	// t_ftlist	tokens;
	// t_ftlist	slices;
	t_ftlist	redirs;

	redirs = parse_context(line, (t_context){
			.def_func = default_mode,
			.dquotes_func = NULL,
			.squotes_func = NULL,
			.end_func = end_func
		});

	return (redirs);
}

// Last found: // *
//             // wc < file1.txt
// Iter        // #
// mode = DEFAULT

// [PENDENTE]: Implementar separação de pedaços da string da linha, em pequenos pedaços

static void	default_mode(t_splitter *sp)
{
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
			slice->type = REDIR_HEREDOC;
		else
			slice->type = REDIR_IN;
	}
	else if (*sp->iter == '>')
	{
		if (*(sp->iter + 1) == '>')
			slice->type = REDIR_APPEND;
		else
			slice->type = REDIR_OUT;
	}
	if (slice->type == REDIR_NONE)
		free(slice);
	else
	{
		slice->start = (char *) sp->iter;	// Temporário (alocar antes de atribuir) Obs: Não sei se é pra alocar aqui mesmo, mas precisa alocar
		if (slice->type == REDIR_APPEND || slice->type == REDIR_HEREDOC)
			sp->iter++;
		ft_lst_push_back(&(sp->list), slice);
	}
}

/* This function does nothing (but it's not useless) :) */
static void	end_func(t_splitter *sp)
{
	if (sp)
		return ;
	return ;
}
