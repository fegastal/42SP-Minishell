/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tmp_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:34:07 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 16:27:43 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	This function generates a temporary file name
*/
char	*get_tmp_file_name(void)
{
	char	*tmp_name;
	char	*str_index;
	int		i;

	i = 0;
	str_index = ft_itoa(i);
	tmp_name = ft_xstr_append("tmp", str_index);
	free(str_index);
	while (!access (tmp_name, F_OK))
	{
		free(tmp_name);
		str_index = ft_itoa(i);
		tmp_name = ft_xstr_append("tmp", str_index);
		free(str_index);
		i += 1;
	}
	return (tmp_name);
}
