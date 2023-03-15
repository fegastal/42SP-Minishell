/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_redir_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:38:48 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 20:38:48 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
	Dynamically allocates memory for a new element in a chained
	list of redirects (t_redir_slice), initializes its fields with
	the values passed as arguments, and returns a pointer to this
	new element.
*/
t_redir_slice	*new_redir_slice(int type, int fd, char *str)
{
	t_redir_slice	*slice;
	char	*start;
	char	*end;
	char	*temp;

	slice = malloc(sizeof(t_redir_slice));
	slice->type = type;
	slice->fd = fd;
	slice->str = str;
	// ft_xstr_supplant(&slice->str, ft_xstr_replace(slice->str, "\"", ""));
	// ft_xstr_supplant(&slice->str, ft_xstr_replace(slice->str, "'", ""));


	start = str;																// Em testes
	end = str + ft_strlen(str) - 1;												// Em testes
	if ((*start == '"' && *end == '"')											// Em testes
		|| (*start == '\'' && *end == '\''))									// Em testes
	{																			// Em testes
		start++;																// Em testes
		end--;																	// Em testes
	}																			// Em testes
	temp = ft_strndup(start, end - start + 1);									// Em testes
	ft_xstr_supplant(&slice->str, temp);										// Em testes

	ft_xstr_supplant(&slice->str, ft_strtrim(slice->str, " "));
	if (type != REDIR_NONE)
		ft_xstr_supplant(&slice->str, expand_file_path(slice->str));
	return (slice);
}
