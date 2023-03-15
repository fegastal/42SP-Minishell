/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_no_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:01:05 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/15 15:01:05 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*get_str_no_quotes(char *str)
{
	const char	*start;
	const char	*end;
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
	return (ft_strndup(start, end - start + 1));
}
