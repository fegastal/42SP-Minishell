/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:31:32 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/21 11:31:32 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static int	iter_cmp(void *tk1, void *tk2);

/*
*	Return next token from start, with code. Token <start> must be a part
*	of tkn->tokens. Note that <start> is not included in the search.
*	If <start> is NULL, the iteration starts from the first token.
*	If no token is found, return NULL.
*/
t_token	*tknext(t_tokenizer *tkn, t_token *start, int code)
{
	t_token		*tk;
	t_ftnode	*node;

	if (tkn == NULL)
		return (NULL);
	if (start == NULL)
		node = tkn->tokens->front;
	else
	{
		node = ft_lst_find(tkn->tokens, start, iter_cmp);
		if (node == NULL)
			return (NULL);
		node = node->next;
	}
	while (node != NULL)
	{
		tk = (t_token *) node->content;
		if (tkcode_cmp(tk, code))
			return (tk);
		node = node->next;
	}
	return (NULL);
}

/*
*	Return previous token from start, with code. Token <start> must be a part
*	of tkn->tokens. Note that <start> is not included in the search.
*	If <start> is NULL, the iteration starts from the last token.
*	If no token is found, return NULL.
*/
t_token	*tkprev(t_tokenizer *tkn, t_token *start, int code)
{
	t_token		*tk;
	t_ftnode	*node;

	if (tkn == NULL)
		return (NULL);
	if (start == NULL)
		node = tkn->tokens->back;
	else
	{
		node = ft_lst_find(tkn->tokens, start, iter_cmp);
		if (node == NULL)
			return (NULL);
		node = node->prev;
	}
	while (node != NULL)
	{
		tk = (t_token *) node->content;
		if (tkcode_cmp(tk, code))
			return (tk);
		node = node->prev;
	}
	return (NULL);
}

static int	iter_cmp(void *tk1, void *tk2)
{
	return (tkcmp((t_token *) tk1, (t_token *) tk2));
}
