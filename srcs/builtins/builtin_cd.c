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
	set_ev(ft_strdup("OLDPWD"), cwd);
	if (chdir(tmp) == -1)
	{
		free(tmp);
		return (no_such_file_or_dir_error());
	}
	set_ev("PWD", tmp);
	return (ERR_NO_ERROR);
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
		else
			tmp = ft_xstr_join("/", cwd, cmd->args[1]);
	}
	return (tmp);
}

// int	builtin_cd(t_cmd *cmd)
// {
// 	t_ev	*home_ev;
// 	char	*cwd;
// 	char	*tmp;

// 	if (cmd->args_count > 2)
// 	{
// 		error(ERR_WRONG_BUILTIN_ARGS, NULL);
// 		return (ERR_WRONG_BUILTIN_ARGS);
// 	}
// 	home_ev = get_ev("HOME");
// 	if (home_ev == NULL)
// 	{
// 		error(ERR_HOME_NOT_SET, NULL);
// 		return (ERR_HOME_NOT_SET);
// 	}
// 	cwd = getcwd(NULL, 0);
// 	if (cmd->args_count == 1)
// 		tmp = ft_strdup(home_ev->value);
// 	else
// 	{
// 		if (!ft_strcmp(cmd->args[1], "~") || !ft_strcmp(home_ev->value, "~/"))
// 			tmp = ft_strdup(home_ev->value);
// 		else
// 			tmp = ft_xstr_join("/", cwd, cmd->args[1]);
// 	}
// 	set_ev(ft_strdup("OLDPWD"), cwd);
// 	if (chdir(tmp) == -1)
// 	{
// 		free(tmp);
// 		error(ERR_NO_SUCH_FILE_OR_DIR, NULL);
// 		return (ERR_NO_SUCH_FILE_OR_DIR);
// 	}
// 	set_ev("PWD", tmp);
// 	return (ERR_NO_ERROR);
// }
