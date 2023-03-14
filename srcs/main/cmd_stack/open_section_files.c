/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_section_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:03:49 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 16:51:52 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_section_slice(t_section_slice *slice,
				t_section_context *context);
static void	open_heredoc(t_section_slice *slice);

/*
	Analyzes a command section to determine which
	files need to be opened or created for incoming
	or outgoing redirection.
*/
t_section_context	open_section_files(t_section *section)
{
	t_section_slice		*slice;
	t_ftnode			*node;
	t_section_context	context;

	context = (t_section_context){0};
	node = section->front;
	while (node != NULL)
	{
		slice = (t_section_slice *) node->content;
		if (slice->type == REDIR_OUT || slice->type == REDIR_APPEND)
			context.last_outfile = slice;
		else if (slice->type == REDIR_IN || slice->type == REDIR_HEREDOC)
			context.last_infile = slice;
		if (!open_section_slice(slice, &context))
			break ;
		node = node->next;
	}
	return (context);
}

static int	open_section_slice(t_section_slice *slice,
	t_section_context *context)
{
	if (slice->type != REDIR_CMD)												// Em testes
		ft_xstr_supplant(&slice->str, ft_xstr_replace(slice->str, "\"", ""));	// Em testes
	if (slice->type == REDIR_CMD)
	{
		if (context->first_cmd == NULL)
			context->first_cmd = slice;
		else
		{
			ft_xstr_supplant(&context->first_cmd->str,
				ft_xstr_join(" ", context->first_cmd->str, slice->str));
		}
	}
	else if (slice->type == REDIR_OUT)
		slice->fd = open(slice->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (slice->type == REDIR_APPEND)
		slice->fd = open(slice->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (slice->type == REDIR_IN)
		slice->fd = open(slice->str, O_RDONLY);
	else if (slice->type == REDIR_HEREDOC)
		open_heredoc(slice);
	if (slice->type != REDIR_CMD && slice->fd == -1)
		return (file_permission_error());
	return (1);
}

static void	open_heredoc(t_section_slice *slice)
{
	int		pid;
	char	*input;
	char	*filename;

	filename = get_tmp_file_name();
	slice->fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (slice->fd == -1)
		return ;
	pid = fork();
	if (pid == 0)
	{
		input = readline("> ");
		while (ft_strcmp(input, slice->str))
		{
			write(slice->fd, input, ft_strlen(input));
			write(slice->fd, "\n", 1);
			ft_xstr_supplant(&input, readline("> "));
		}
		free(input);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	close(slice->fd);
	slice->fd = open(filename, O_RDONLY);
	ft_xstr_supplant(&slice->str, filename);
}
