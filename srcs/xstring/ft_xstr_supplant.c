/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstr_supplant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:51:46 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/05 16:51:46 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xstring.h"

/*
	This function frees the string pointed to by str and replaces it with the
	string pointed to by new.
*/
void	ft_xstr_supplant(char **str, char *new)
{
	if (str == NULL)
		return ;
	if (*str != NULL)
		free(*str);
	*str = new;
}
