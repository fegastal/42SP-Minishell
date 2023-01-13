/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstr_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:12:56 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/01/03 10:12:56 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xstring.h"

static size_t	populate_strlist(va_list args, unsigned int count,
					t_ftlist *strlist);
static char		*join_strings(t_ftlist strlist, const char *sep, size_t len);
static size_t	copy_str(char *dst, const char *src);

/*
	Concatenate multiple strings into one, separated by 'sep' string, then
	return it.
*/
char	*ft_xstr_join(const char *sep, unsigned int count, ...)
{
	va_list		args;
	t_ftlist	strlist;
	char		*final_str;
	size_t		len;

	va_start(args, count);
	ft_lst_init(&strlist);
	len = ft_strlen(sep) * (count - 1);
	len += populate_strlist(args, count, &strlist);
	final_str = join_strings(strlist, sep, len);
	ft_lst_clear(&strlist, NULL);
	va_end(args);
	return (final_str);
}

/*
	Fill strlist with args values, then return the total length.
*/
static size_t	populate_strlist(va_list args, unsigned int count,
					t_ftlist *strlist)
{
	unsigned int	i;
	size_t			len;
	char			*tmp;

	len = 0;
	i = 0;
	while (i < count)
	{
		tmp = va_arg(args, char *);
		ft_lst_push_back(strlist, tmp);
		len += ft_strlen(tmp);
		i += 1;
	}
	return (len);
}

static char	*join_strings(t_ftlist strlist, const char *sep, size_t len)
{
	t_ftnode	*iter;
	char		*str;
	int			i;

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	iter = strlist.front;
	i = 0;
	while (iter != NULL)
	{
		i += copy_str(str + i, iter->content);
		if (iter->next != NULL)
			i += copy_str(str + i, sep);
		iter = iter->next;
	}
	str[i] = '\0';
	return (str);
}

/*
	Copy string 'src' into 'dst' (truncating).
*/
static size_t	copy_str(char *dst, const char *src)
{
	size_t	len;

	len = 0;
	while (src[len] != '\0')
	{
		dst[len] = src[len];
		len += 1;
	}
	return (len);
}
