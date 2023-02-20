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

void	builtin_cd(t_cmd *cmd)
{
	t_ev	*home_ev;
	char	*cwd;
	char	*tmp;

	if (cmd->args_count > 2)
		return ;	// Mudar por erro (too many arguments)
	home_ev = get_ev("HOME");
	if (home_ev == NULL)
		return ;	// Mudar por erro (HOME not set)
	if (cmd->args_count == 1
		|| !ft_strcmp(home_ev->value, "~")
		|| !ft_strcmp(home_ev->value, "~/"))
	{
		tmp = ft_strdup(home_ev->value);
		// if (chdir(home_ev->value) == -1)
		// 	return ;	// Mudar por erro (no such file or directory)
	}
	else
	{
		cwd = getcwd(NULL, 0);
		tmp = ft_xstr_join("/", cwd, cmd->args[1]);
		// if (chdir(ft_xstr_join("/", cwd, cmd->args[1])) == -1)
		// 	return ;	// Mudar por erro (no such file or directory)
		free(cwd);
	}
	if (chdir(tmp) == -1)
	{
		free(tmp);
		return ;	// Mudar por erro (no such file or directory)
	}
	set_ev("PWD", tmp);
}

// void	builtin_cd(t_cmd *cmd)
// {
// 	char	*target_path;
// 	t_ev	*home_ev;
// 	t_ev	*pwd_ev;

// 	if (cmd->args_count > 2)
// 		return ;	// Mudar por erro (too many arguments)
// 	home_ev = get_ev("HOME");
// 	if (home_ev == NULL)
// 		return ;	// Mudar por erro (HOME not set)
// 	else if (cmd->args_count == 1)
// 		target_path = ft_strdup(home_ev->value);
// 	else if (cmd->args[1][0] == '~')
// 		target_path = ft_strjoin(home_ev->value, cmd->args[1] + 1);
// 	else
// 	{
// 		pwd_ev = get_ev("PWD");
// 		if (pwd_ev == NULL)
// 			return ;	// Mudar por erro (PWD not set)
// 		target_path = ft_xstr_join("/", pwd_ev->value, cmd->args[1]);
// 	}
// 	if (chdir(target_path) == -1)
// 		return ;	// Mudar por erro (no such file or directory)
// 	printf("target_path: %s\n", target_path);
// 	chdir(target_path);
// 	set_ev("PWD", target_path);
// }
