/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:41:16 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/01/10 13:41:16 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	builtin_pwd(void)
{
	char *temp;

	temp = getcwd(NULL, 0);
	printf("%s\n", temp);
	free(temp);
	exit(0);
	return (0);
}
