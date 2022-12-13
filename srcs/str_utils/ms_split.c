/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:56:56 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/12/09 15:56:56 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ftlist	ms_split(const char *str, const char *sep)
{
	t_ftlist	list;
	const char	*start;
	const char	*iter;
	size_t		i;
	char		*tmp;

	ft_lst_init(&list);
	if (str == NULL)
		return (list);
	iter = str;
	start = iter;
	while (*iter != '\0')
	{
		i = 0;
		while (*(iter + i) == sep[i] && *(iter + i) != '\0' && sep[i] != '\0')
			i += 1;
		if (ft_strlen(sep) == i || *(iter + i) == '\0')
		{
			tmp = ft_strndup(start, iter - start);
			if (tmp == NULL)
			{
				ft_lst_clear(&list, free);
				return (list);
			}
			if (ft_lst_push_back(&list, tmp) == NULL)
			{
				free(tmp);
				ft_lst_clear(&list, free);
				return (list);
			}
			start = iter + i;
			iter = start;
		}
		iter++;
	}
	return (list);
}

