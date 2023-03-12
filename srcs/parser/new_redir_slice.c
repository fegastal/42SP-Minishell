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

t_redir_slice	*new_redir_slice(int type, int fd, char *str)
{
	t_redir_slice	*slice;

	slice = malloc(sizeof(t_redir_slice));
	slice->str = str;
	slice->type = type;
	slice->fd = fd;
	return (slice);
}
