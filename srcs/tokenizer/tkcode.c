/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:33:37 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/20 19:33:37 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

/*
*	Return token code (as int) from tkn->tk_table,
	based on token char (chr).
	If chr is not found in tk_table, return -1.
*/
int tkcode(t_tokenizer *tkn, char chr)
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
