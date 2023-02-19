/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstr_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:09:51 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/18 10:09:51 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xstring.h"

char	*ft_xstr_append(const char *str1, const char *str2)
{
	char	*new_str;
	size_t	len;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	else if (str1 == NULL)
		return (ft_strdup(str2));
	else if (str2 == NULL)
		return (ft_strdup(str1));
	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	new_str = malloc(sizeof(char) * len);
	ft_strlcpy(new_str, str1, len);
	ft_strlcat(new_str, str2, len);
	return (new_str);
}
