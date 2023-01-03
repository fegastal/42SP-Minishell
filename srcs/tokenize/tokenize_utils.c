/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:04:20 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/12/28 13:04:20 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

/*
	Return a token number based on t_token_types enum, of the given
	character (char).
*/
int	get_token_type(char chr)
{
	int	i;

	if (chr == '\0')
		return (TKTYPE_END);
	i = 0;
	while (VALID_TOKENS[i] != '\0')
	{
		if (chr == VALID_TOKENS[i])
			return (i);
		i += 1;
	}
	return (TKTYPE_INVALID);
}

/*
	[For Debug Purposes]
	Return the string name of a token (token_type).
*/
char	*get_token_name(int token_type)
{
	static char	*names[] = {
		"TKTYPE_WHITESPACE",
		"TKTYPE_PIPE",
		"TKTYPE_DOLLAR",
		"TKTYPE_QUESTION_MARK",
		"TKTYPE_STR_SINGLE",
		"TKTYPE_STR_DOUBLE",
		"TKTYPE_ABRACK_LEFT",
		"TKTYPE_ABRACK_RIGHT",
		"TKTYPE_MINUS",
		"TKTYPE_START",
		"TKTYPE_END",
		"TKTYPE_INVALID"
	};

	return (names[token_type]);
}

void	clear_tokens(t_msh_tknz **tk)
{
	int	i;

	if (tk == NULL || *tk == NULL)
		return ;
	i = 0;
	while (i < TOKENS_COUNT)
	{
		ft_lst_clear((*tk)->tokens + i, free);
		i += 1;
	}
	free((*tk)->tokens);
	free(*tk);
	*tk = NULL;
}
