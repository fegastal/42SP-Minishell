/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstr_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:27:25 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/11 18:27:25 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xstring.h"

static void	loop(const char **str_ptr, const char *old_ptr,
				const char *new, char **new_str);

char	*ft_xstr_replace(const char *str, const char *old, const char *new)
{
	const char	*str_ptr;
	char		*new_str;

	if (str == NULL)
		return (NULL);
	else if (old == NULL || new == NULL)
		return (ft_strdup(str));
	new_str = ft_strdup("");
	str_ptr = str;
	while (*str_ptr != '\0')
		loop(&str_ptr, old, new, &new_str);
	return (new_str);
}

static void	loop(const char **str_ptr, const char *old_ptr,
				const char *new, char **new_str)
{
	const char	*aux;
	char		*temp;

	aux = *str_ptr;
	while (*old_ptr != '\0' && *aux == *old_ptr)
	{
		aux++;
		old_ptr++;
	}
	if (*old_ptr == '\0')
	{
		ft_xstr_supplant(new_str, ft_xstr_append(*new_str, new));
		*str_ptr = aux;
	}
	else
	{
		temp = ft_strndup(*str_ptr, 1);
		ft_xstr_supplant(new_str, ft_xstr_append(*new_str, temp));
		free(temp);
		(*str_ptr)++;
	}
}
