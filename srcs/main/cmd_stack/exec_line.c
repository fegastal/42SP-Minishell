/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:26:18 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/20 12:26:18 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_pipe_cmd(void *line, size_t i, int is_first, int is_last)
{
	t_cmd	*cmd;

	cmd = new_cmd((const char *) line);
	if (cmd == NULL)	// Caso de linha somente com espaços
		return ;	// Exibir mensagem de erro
	else if (cmd->path == NULL && !cmd->is_builtin)	// Caso de comando não encontrado
	{
		printf("minishell: %s: command not found\n", cmd->args[0]);
		g_core.last_status = 127;
		clear_cmd(cmd);
		return ;
	}
	exec_cmd(cmd, is_first, is_last);
	if (is_first && is_last && !ft_strcmp(cmd->args[0], "exit"))
		g_core.is_running = IS_NOT_RUNNING;
	clear_cmd(cmd);
	i = i;
}

void	exec_line(const char *line)
{
	t_ftlist	pipe_list;

	pipe_list = pipe_split_line(line);
	ft_lst_func_apply(&pipe_list, exec_pipe_cmd);
	ft_lst_clear(&pipe_list, free);
	// dup2(g_core.std_in, STDIN_FILENO);
	// dup2(g_core.std_out, STDOUT_FILENO);
}
