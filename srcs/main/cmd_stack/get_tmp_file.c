/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_tmp_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:34:07 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/05 09:34:07 by lsilva-q         ###   ########.fr       */
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
	while(!access(tmp_name, F_OK))
	{
		free(tmp_name);
		str_index = ft_itoa(i);
		tmp_name = ft_xstr_append("tmp", str_index);
		free(str_index);
		i += 1;
	}
	return (tmp_name);
}
