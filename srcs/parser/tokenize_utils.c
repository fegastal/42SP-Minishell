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

#include "minishell.h"

int	get_token_type(char chr)
{
	int	i;

	if (chr == '\0')
		return (TKTYPE_END);
	i = 0;
	while (ALL_TOKEN_CHARS[i] != '\0')
	{
		if (chr == ALL_TOKEN_CHARS[i])
			return (i);
		i += 1;
	}
	return (TKTYPE_INVALID);
}

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

void	clear_tokens(t_ftlist **tokens)
{
	int	i;

	if (tokens == NULL)
		return ;
	i = 0;
	while (i < TOKENS_COUNT)
	{
		ft_lst_clear(*tokens + i, free);
		i += 1;
	}
	free(*tokens);
	*tokens = NULL;
}
