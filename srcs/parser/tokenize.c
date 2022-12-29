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

#include "minishell.h"

static void	init_array(t_ftlist **arr);
static void	place_token(t_ftlist *list, char *ptr, int type);

/*
	Return a token array, containing all tokens from a string. Each index from
	the array represents a token from t_token_types (except TKTYPE_INVALID).
*/
t_ftlist	*tokenize(char *str)
{
	char		*iter;
	int			type;
	t_ftlist	*arr;

	if (str == NULL)
		return (NULL);
	init_array(&arr);
	place_token(arr, str, TKTYPE_START);
	iter = str;
	while (*iter != '\0')
	{
		type = get_token_type(*iter);
		if (type != TKTYPE_INVALID)
			place_token(arr, iter, type);
		iter++;
	}
	place_token(arr, iter, TKTYPE_END);
	return (arr);
}

static void	init_array(t_ftlist **arr)
{
	int	i;

	*arr = malloc(sizeof(t_ftlist) * TOKENS_COUNT);
	i = 0;
	while (i < TOKENS_COUNT)
	{
		// printf("%i -> %i\n", i, ft_lst_init(*arr + i));
		ft_lst_init(*arr + i);
		i += 1;
	}
}

static void	place_token(t_ftlist *arr, char *ptr, int type)
{
	t_msh_token	*token;

	token = malloc(sizeof(t_msh_token));
	token->ptr = ptr;
	token->type = type;
	ft_lst_push_back(arr + type, token);
}
