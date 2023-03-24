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
	context.is_valid = 1;
	node = section->front;
	while (node != NULL)
	{
		slice = (t_section_slice *) node->content;
		node = node->next;
		if (!context.is_valid && slice->type != REDIR_HEREDOC)
			continue ;
		if (slice->type == REDIR_OUT || slice->type == REDIR_APPEND)
			context.last_outfile = slice;
		else if (slice->type == REDIR_IN || slice->type == REDIR_HEREDOC)
			context.last_infile = slice;
		if (!open_section_slice(slice, &context))
			context.is_valid = 0;
	}
	return (context);
}

static int	open_section_slice(t_section_slice *slice,
	t_section_context *context)
{
	print_section_slice(slice, "Opening slice: ");								// DEBUG
	if (slice->type != REDIR_CMD)												// Em testes
		ft_xstr_supplant(&slice->str, ft_xstr_rmv_set(slice->str, "\"'"));		// Em testes
	if (slice->type == REDIR_CMD)												// DEBUG
		ft_putstr_fd("Entered REDIR_CMD!\n", 1);								// DEBUG
	else if (slice->type == REDIR_OUT)											// DEBUG
		ft_putstr_fd("Entered REDIR_OUT!\n", 1);								// DEBUG
	else if (slice->type == REDIR_APPEND)										// DEBUG
		ft_putstr_fd("Entered REDIR_APPEND!\n", 1);								// DEBUG
	else if (slice->type == REDIR_IN)											// DEBUG
		ft_putstr_fd("Entered REDIR_IN!\n", 1);									// DEBUG
	else if (slice->type == REDIR_HEREDOC)										// DEBUG
		ft_putstr_fd("Entered REDIR_HEREDOC!\n", 1);							// DEBUG
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
	{
		ft_putstr_fd("Opening heredoc!\n", 1);									// DEBUG
		open_heredoc(slice);
	}
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
		ft_putstr_fd("Checking if \"", 1);										// DEBUG
		ft_putstr_fd(input, 1);													// DEBUG
		ft_putstr_fd("\" is equal to \"", 1);									// DEBUG
		ft_putstr_fd(slice->str, 1);											// DEBUG
		ft_putstr_fd("\"!\n", 1);												// DEBUG
		while (ft_strcmp(input, slice->str))
		{
			ft_putstr_fd("\tIt is not equal!\n", 1);							// DEBUG
			write(slice->fd, input, ft_strlen(input));
			write(slice->fd, "\n", 1);
			ft_xstr_supplant(&input, readline("> "));
		}
		ft_putstr_fd("\tIt is equal!\n", 1);									// DEBUG
		free(input);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	close(slice->fd);
	slice->fd = open(filename, O_RDONLY);
	ft_xstr_supplant(&slice->str, filename);
}
