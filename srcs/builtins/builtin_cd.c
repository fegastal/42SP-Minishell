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

static char	*get_new_pwd(char *cwd, const char *home_path, t_cmd *cmd);

/*
	This function checks arguments and sets environment
	variables before changing the working directory.
	It returns with an error if the "HOME" environment
	variable is not set or there is an error
	changing the working directory.
*/
int	builtin_cd(t_cmd *cmd)
{
	char	*home_path;
	char	*cwd;
	char	*tmp;

	if (cmd->args_count > 2)
		return (wrong_builtin_args_error());
	home_path = get_ev_value("HOME");
	if (home_path == NULL)
		return (home_not_set_error());
	cwd = getcwd(NULL, 0);
	tmp = get_new_pwd(cwd, home_path, cmd);
	free(home_path);
	if (chdir(tmp) == -1)
	{
		if (tmp != NULL)
			free(tmp);
		if (cwd != NULL)
			free(cwd);
		return (no_such_file_or_dir_error());
	}
	set_ev(ft_strdup("OLDPWD"), cwd);
	ft_xstr_supplant(&tmp, getcwd(NULL, 0));
	set_ev(ft_strdup("PWD"), tmp);
	return (ERR_SUCCESS);
}

static char	*get_new_pwd(char *cwd, const char *home_path, t_cmd *cmd)
{
	char	*tmp;

	if (cmd->args_count == 1)
		tmp = ft_strdup(home_path);
	else
	{
		if (!ft_strcmp(cmd->args[1], "~") || !ft_strcmp(home_path, "~/"))
			tmp = ft_strdup(home_path);
		else if (*(cmd->args[1]) == '/')
			tmp = ft_strdup(cmd->args[1]);
		else
			tmp = ft_xstr_join("/", cwd, cmd->args[1]);
	}
	return (tmp);
}
