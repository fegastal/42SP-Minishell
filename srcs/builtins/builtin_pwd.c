/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:41:16 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 16:19:59 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/*
	The function "builtin_pwd" implements the shell command "pwd"
	by getting the current directory using the function "getcwd()"
	and printing it on standard output using "printf()".
*/
int	builtin_pwd(t_cmd *cmd)
{
	char	*temp;

	(void) cmd;
	temp = getcwd(NULL, 0);
	printf("%s\n", temp);
	free(temp);
	return (0);
}
