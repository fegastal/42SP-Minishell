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

void	place_token(t_ftlist *list, char *ptr, int type);

t_ftlist	tokenize(char *str)
{
	char		*iter;
	int			type;
	t_ftlist	list;

	ft_lst_init(&list);
	iter = str;
	while (*iter != '\0')
	{
		type = get_token_type(*iter);
		if (type != TKTYPE_INVALID)
			place_token(&list, iter, type);
		iter++;
	}
	return (list);
}

void	place_token(t_ftlist *list, char *ptr, int type)
{
	t_msh_token	*token;

	if (list == NULL)
		return ;
	token = malloc(sizeof(t_msh_token));
	token->ptr = ptr;
	token->type = token;
	ft_lst_push_back(list, token);
}
