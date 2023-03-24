/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_tokenize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:52:04 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/20 19:52:04 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static t_tokenizer	*tkn_init(const char *str, const char *tk_table);

/*
*	Iters through the string and generates a list of tokens, then
*	returns a t_tokenizer struct containing the tokens, the string and
*	the token table.
*/
t_tokenizer	*tkn_tokenize(const char *str, const char *tk_table)
{
	t_tokenizer	*tkn;
	t_token		*tk;
	const char	*iter;
	int			code;

	tkn = tkn_init(str, tk_table);
	iter = tkn->str;
	while (*iter)
	{
		code = tkcode(tkn, *iter);
		if (code != -1)
		{
			tk = malloc(sizeof(t_token));
			*tk = (t_token){iter, code};
			ft_lst_push_back(&tkn->tokens, tk);
		}
		iter++;
	}
	return (tkn);
}

/*
	Allocates a tokenizer struct and initializes it with the given parameters,
	returning a pointer to it.
*/
static t_tokenizer	*tkn_init(const char *str, const char *tk_table)
{
	t_tokenizer	*tkn;

	tkn = malloc(sizeof(t_tokenizer));
	*tkn = (t_tokenizer){str, tk_table, 0};
	return (tkn);
}
