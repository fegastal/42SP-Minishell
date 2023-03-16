/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstr_rmv_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:53:20 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/16 17:53:20 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xstring.h"

/*
	Iterates through the string and removes all characters from the set.
*/
char	*ft_xstr_rmv_set(const char *str, const char *set)
{
	const char	*iter;
	const char	*dup_start;
	char		*new;

	if (str == NULL)
		return (NULL);
	if (set == NULL)
		ft_strdup(str);
	new = NULL;
	dup_start = NULL;
	iter = str;
	while (*iter)
	{
		if (dup_start == NULL && !ft_strchr(set, *iter))
			dup_start = iter;
		else if (dup_start != NULL && ft_strchr(set, *iter))
		{
			ft_xstr_supplant(&new,
				ft_xstr_append(new, ft_strndup(dup_start, iter - dup_start)));
			dup_start = NULL;
		}
	}
	return (new);
}
