/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:41:16 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/13 19:31:47 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	handle_single_builtin_redirs(void);
static void	reset_single_builtin_redirs(void);

/*
	The function call_builtin calls the shell's builtins
	by identifying which command is being requested based
	on the first argument and calling the corresponding
	function to execute it.
*/
int	call_builtin(t_cmd *cmd)
{
	char	*name;
	int		status;

	status = 0;
	name = cmd->args[0];
	if (!ft_strcmp(name, "echo"))
		status = builtin_echo(cmd);
	else if (!ft_strcmp(name, "export"))
		status = builtin_export(cmd);
	else if (!ft_strcmp(name, "pwd"))
		status = builtin_pwd(cmd);
	else if (!ft_strcmp(name, "unset"))
		status = builtin_unset(cmd);
	else if (!ft_strcmp(name, "env"))
		status = builtin_env(cmd);
	else if (!ft_strcmp(name, "cd"))
		status = builtin_cd(cmd);
	else if (!ft_strcmp(name, "exit"))
		exit(builtin_exit(cmd));
	if (status == 0)
		exit(0);
	return (-1);
}

int	call_single_builtin(t_cmd *cmd)
{
	char	*name;
	int		status;

	handle_single_builtin_redirs();
	status = 0;
	name = cmd->args[0];
	if (!ft_strcmp(name, "echo"))
		status = builtin_echo(cmd);
	else if (!ft_strcmp(name, "export"))
		status = builtin_export(cmd);
	else if (!ft_strcmp(name, "pwd"))
		status = builtin_pwd(cmd);
	else if (!ft_strcmp(name, "unset"))
		status = builtin_unset(cmd);
	else if (!ft_strcmp(name, "env"))
		status = builtin_env(cmd);
	else if (!ft_strcmp(name, "cd"))
		status = builtin_cd(cmd);
	else if (!ft_strcmp(name, "exit"))
		status = builtin_exit(cmd);
	reset_single_builtin_redirs();
	return (status);
}

static void	handle_single_builtin_redirs(void)
{
	if (g_core.fd_in_type == FD_REDIR_STD)
		dup2(g_core.std_in, STDIN_FILENO);
	else if (g_core.fd_in_type == FD_REDIR_FILE)
		dup2(g_core.fd_in, STDIN_FILENO);
	if (g_core.fd_out_type == FD_REDIR_STD)
		dup2(g_core.std_out, STDOUT_FILENO);
	else if (g_core.fd_out_type == FD_REDIR_FILE)
		dup2(g_core.fd_out, STDOUT_FILENO);
}

static void	reset_single_builtin_redirs(void)
{
	dup2(g_core.std_in, STDIN_FILENO);
	dup2(g_core.std_out, STDOUT_FILENO);
}
