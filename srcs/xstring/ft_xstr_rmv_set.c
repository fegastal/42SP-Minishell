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

static void	append_to_str(char **str, char *new);

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
	while (*iter != '\0')
	{
		if (dup_start == NULL && !ft_strchr(set, *iter))
			dup_start = iter;
		else if (dup_start != NULL && ft_strchr(set, *iter))
		{
			append_to_str(&new, ft_strndup(dup_start, iter - dup_start));
			dup_start = NULL;
		}
		iter++;
	}
	if (dup_start != NULL)
		append_to_str(&new, ft_strdup(dup_start));
	return (new);
}

static void	append_to_str(char **str, char *new)
{
	char	*tmp;

	tmp = ft_xstr_append(*str, new);
	free(new);
	ft_xstr_supplant(str, tmp);
}
