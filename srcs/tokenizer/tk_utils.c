/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:17:47 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/21 11:17:47 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

/*
*	Return token code (as int) from tkn->tk_table,
*	based on token char (chr).
*	If chr is not found in tk_table, return -1.
*/
int	tkcode(t_tokenizer *tkn, char chr)
{
	const char	*iter;

	if (tkn == NULL)
		return (-1);
	iter = tkn->tk_table;
	while (*iter)
	{
		if (*iter == chr)
			return (iter - tkn->tk_table);
		iter++;
	}
	return (-1);
}

/*
*	Compare two tokens. Return 1 if they are equal, 0 otherwise.
*/
int	tkcmp(t_token *tk, t_token *tk2)
{
	if (tk1 == NULL || tk2 == NULL)
		return (0);
	if (tk1->code != tk2->code)
		return (0);
	if (tk1->str != tk2->str)
		return (0);
	return (1);
}

/*
*	Compare token code with code. Return 1 if they are equal, 0 otherwise.
*/
int	tkcode_cmp(t_token *tk, int code)
{
	if (tk == NULL)
		return (0);
	return (tk->code == code);
}
