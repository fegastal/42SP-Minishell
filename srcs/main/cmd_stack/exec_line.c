/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:26:18 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/16 21:26:12 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	run_section(void *content, size_t i, int is_first, int is_last);
static void	redirect_by_context(t_section_context *context,
				int is_first, int is_last);

/*
	Is responsible for executing a command line, which
	can consist of several individual commands, each with
	their own arguments and options, that have been processed
	by the get_line_context() and run_section() functions.
*/
void	exec_line(const char *line)
{
	t_line_context	context;

	if (line == NULL)
		return ;
	g_core.can_proceed = 1;
	context = get_line_context(line);
	if (!context.is_valid)
		return ((void) syntax_error());
	ft_lst_func_apply(&context.sections, run_section);
	ft_lst_clear(&context.sections, clear_section);
}

static void	run_section(void *content, size_t i, int is_first, int is_last)
{
	t_section_context	context;
	t_section			*section;
	t_cmd				*cmd;

	(void) i;
	section = (t_section *) content;
	if (g_core.can_proceed == 0)
		return ;
	context = open_section_files(section);
	if (context.is_valid == 0)
		return (ft_lst_func_apply(section, close_section_files));
	redirect_by_context(&context, is_first, is_last);
	cmd = new_cmd(context.first_cmd->str);
	if (is_first && is_last && is_builtin(cmd->args[0]))
	{
		g_core.last_status = call_single_builtin(cmd);
		if (ft_strcmp(cmd->args[0], "exit") == 0)
			g_core.is_running = IS_NOT_RUNNING;
	}
	else
		exec_cmd(cmd, is_first, is_last);
	clear_cmd(cmd);
	ft_lst_func_apply(section, close_section_files);
}

static void	redirect_by_context(t_section_context *context,
	int is_first, int is_last)
{
	if (context->last_infile != NULL)
	{
		g_core.fd_in = context->last_infile->fd;
		g_core.fd_in_type = FD_REDIR_FILE;
	}
	else
	{
		if (is_first)
			g_core.fd_in_type = FD_REDIR_STD;
		else
			g_core.fd_in_type = FD_REDIR_PIPE;
	}
	if (context->last_outfile != NULL)
	{
		g_core.fd_out = context->last_outfile->fd;
		g_core.fd_out_type = FD_REDIR_FILE;
	}
	else
	{
		if (is_last)
			g_core.fd_out_type = FD_REDIR_STD;
		else
			g_core.fd_out_type = FD_REDIR_PIPE;
	}
}
