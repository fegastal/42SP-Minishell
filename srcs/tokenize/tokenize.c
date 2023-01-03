/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:47:31 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/12/28 12:47:31 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static t_msh_tknz	*new_tknz(void);
static void			place_token(t_msh_tknz *tknz, char *ptr, int type);

/*
	Iterate through a string (str), then create and return a token struct,
	containing all tokens (as an array) from a string and the string. Each
	index from the array represents a token from
	t_token_types (except TKTYPE_INVALID).
	All tokens are given by VALID_TOKENS macro.
*/
t_msh_tknz	*tokenize(char *str)
{
	t_msh_tknz	*tokens;
	char		*iter;
	int			type;

	if (str == NULL)
		return (NULL);
	tokens = new_tknz();
	place_token(tokens, str, TKTYPE_START);
	iter = str;
	while (*iter != '\0')
	{
		type = get_token_type(*iter);
		if (type != TKTYPE_INVALID)
			place_token(tokens, iter, type);
		iter++;
	}
	place_token(tokens, iter, TKTYPE_END);
	return (tokens);
}

static t_msh_tknz	*new_tknz(void)
{
	t_msh_tknz	*tk;
	int			i;

	tk = malloc(sizeof(t_msh_tknz));
	if (tk == NULL)
		return (NULL);
	tk->tokens = malloc(sizeof(t_ftlist) * TOKENS_COUNT);
	if (tk->tokens == NULL)
	{
		free(tk);
		return (NULL);
	}
	i = 0;
	while (i < TOKENS_COUNT)
	{
		ft_lst_init(tk->tokens + i);
		i += 1;
	}
	return (tk);
}

static void	place_token(t_msh_tknz *tknz, char *ptr, int type)
{
	t_msh_token	*token;

	token = malloc(sizeof(t_msh_token));
	token->ptr = ptr;
	token->type = type;
	ft_lst_push_back(tknz->tokens + type, token);
}
