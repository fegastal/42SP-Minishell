/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:40:36 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/05 18:40:36 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	error(int error_code, char *message)
{
	if (error_code == ERR_CUSTOM_ERROR)
	{
		if (message != NULL)
			ft_putstr_fd(message, FD_ERROR);
	}
	else if (error_code == ERR_CMD_NOT_FOUND)
	{
		ft_putstr_fd("command not found: ", FD_ERROR);
		if (message != NULL)
			ft_putstr_fd(message, FD_ERROR);
		ft_putstr_fd("\n", FD_ERROR);
	}
	else
	{
		if (message != NULL)
			ft_putstr_fd(message, FD_ERROR);
		perror("Error");
	}
	return (error_code);
}
