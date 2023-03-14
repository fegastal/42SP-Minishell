/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_file_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:30:50 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/14 18:30:50 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*expand_file_path(const char *filepath)
{
	char	*expanded_path;
	char	*tmp;

	tmp = NULL;
	if (filepath[0] == '~')
	{
		tmp = get_ev_value("HOME");
		if (tmp == NULL)
		{
			home_not_set_error();
			return (NULL);
		}
	}
	else if (filepath[0] == '.' && filepath[1] == '/')
		tmp = getcwd(NULL, 0);
	if (tmp == NULL)
		return (ft_strdup(filepath));
	expanded_path = ft_xstr_append(tmp, filepath + 1);
	free(tmp);
	return (expanded_path);
}
