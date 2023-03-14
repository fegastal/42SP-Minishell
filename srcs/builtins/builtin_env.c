/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:13:33 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/13 19:33:11 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/*
	The builtin_env function prints all defined
	environment variables on the screen.
*/
int	builtin_env(t_cmd *cmd)
{
	char	**envp;

	if (cmd->args_count != 1)
	{
		error(ERR_CUSTOM_ERROR, "Error: Too many arguments!\n");
		return (ERR_WRONG_BUILTIN_ARGS);
	}
	envp = g_core.envp;
	while (*envp != NULL)
	{
		printf("%s\n", *envp);
		envp++;
	}
	return (0);
}
