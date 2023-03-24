/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_no_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:01:05 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/16 21:34:30 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*get_str_no_quotes(const char *str)
{
	const char	*start;
	const char	*end;
	char		*new_str;
	size_t		len;

	len = ft_strlen(str);
	start = str;
	end = str + len - 1;
	if (len > 1 && ((*start == '"' && *end == '"')
			|| (*start == '\'' && *end == '\'')))
	{
		start++;
		end--;
	}
	new_str = ft_strndup(start, end - start + 1);
	return (new_str);
}
