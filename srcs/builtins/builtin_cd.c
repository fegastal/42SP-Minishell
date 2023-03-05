/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:00:17 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/19 19:00:17 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	builtin_cd(t_cmd *cmd)
{
	t_ev	*home_ev;
	char	*cwd;
	char	*tmp;

	if (cmd->args_count > 2)
		return (1);	// Erro too many arguments
	home_ev = get_ev("HOME");
	if (home_ev == NULL)
		return (1);	// Erro HOME not set
	if (cmd->args_count == 1
		|| !ft_strcmp(home_ev->value, "~")
		|| !ft_strcmp(home_ev->value, "~/"))
	{
		tmp = ft_strdup(home_ev->value);
	}
	else
	{
		cwd = getcwd(NULL, 0);
		tmp = ft_xstr_join("/", cwd, cmd->args[1]);
		free(cwd);
	}
	if (chdir(tmp) == -1)
	{
		free(tmp);
		return (1);	// Erro no such file or directory
	}
	set_ev("PWD", tmp);
	return (0);
}
