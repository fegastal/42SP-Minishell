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
	int		i;

	i = 0;
	tmp_name = ft_xstr_append("tmp", ft_itoa(i));
	while(!access(tmp_name, F_OK))
	{
		free(tmp_name);
		tmp_name = ft_xstr_append("tmp", ft_itoa(++i));
		i += 1;
	}
	return (tmp_name);
}
