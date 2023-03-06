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
	{
		error(ERR_WRONG_BUILTIN_ARGS, NULL);
		return (ERR_WRONG_BUILTIN_ARGS);
	}
	home_ev = get_ev("HOME");
	if (home_ev == NULL)
	{
		error(ERR_HOME_NOT_SET, NULL);
		return (ERR_HOME_NOT_SET);
	}
	cwd = getcwd(NULL, 0);
	if (cmd->args_count == 1)
		tmp = ft_strdup(home_ev->value);
	else
	{
		if (!ft_strcmp(cmd->args[1], "~") || !ft_strcmp(home_ev->value, "~/"))
			tmp = ft_strdup(home_ev->value);
		else
			tmp = ft_xstr_join("/", cwd, cmd->args[1]);
	}
	set_ev(ft_strdup("OLDPWD"), cwd);
	if (chdir(tmp) == -1)
	{
		free(tmp);
		error(ERR_NO_SUCH_FILE_OR_DIR, NULL);
		return (ERR_NO_SUCH_FILE_OR_DIR);
	}
	set_ev("PWD", tmp);
	return (ERR_NO_ERROR);
}
