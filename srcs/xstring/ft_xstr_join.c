/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstr_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:28:03 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/18 10:28:03 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xstring.h"

char	*ft_xstr_join(const char *sep, const char *str1, const char *str2)
{
	char	*new_str;
	char	*tmp;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	else if (str1 == NULL)
		return (ft_strdup(str2));
	else if (str2 == NULL)
		return (ft_strdup(str1));
	if (sep == NULL)
		new_str = ft_strdup(str1);
	else
		new_str = ft_xstr_append(str1, sep);
	tmp = new_str;
	new_str = ft_xstr_append(new_str, str2);
	free(tmp);
	return (new_str);
}
