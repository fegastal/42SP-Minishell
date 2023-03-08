/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_context.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:14:12 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/08 19:14:12 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_redir_slice(void *content);
static void	clean_section(void *content);
static int	is_invalid_slice(void *content, void *new_content);
static void	populate_section(t_line_context *context, t_ftlist *pipe_list);

t_line_context	get_line_context(const char *line)
{
	t_line_context	context;
	t_ftlist		pipe_list;

	context = (t_line_context) {0};
	if (ft_xstr_match_set(line, " "))
	{
		context.is_valid = 0;
		return (context);
	}
	pipe_list = pipe_split_line(line);
	context.sections = (t_ftlist) {0};
	populate_section(&context, &pipe_list);
	if (!context.is_valid)
		ft_lst_clear(&context.sections, clean_section);
	return (context);
}

static void	clean_redir_slice(void *content)
{
	t_redir_slice	*slice;

	slice = (t_redir_slice *) content;
	if (slice->str != NULL)
		free(slice->str);
	free(slice);
}

static void	clean_section(void *content)
{
	t_ftlist	*section;

	section = (t_ftlist *) content;
	ft_lst_clear(section, clean_redir_slice);
	free(section);
}

static int	is_invalid_slice(void *content, void *new_content)
{
	t_redir_slice	*slice;

	(void) new_content;
	slice = (t_redir_slice *) content;
	if (slice->str == NULL || slice->str[0] == '\0')
		return (1);
	return (0);
}

static void	populate_section(t_line_context *context, t_ftlist *pipe_list)
{
	t_ftnode	*iter;
	t_ftlist	*redir_list;

	iter = pipe_list->front;
	while (iter != NULL)
	{
		redir_list = malloc(sizeof(t_ftlist));
		*redir_list = redir_split_line((const char *) iter->content);
		if (ft_lst_find(redir_list, NULL, is_invalid_slice))
		{
			ft_lst_clear(redir_list, clean_redir_slice);
			context->is_valid = 0;
			return ;
		}
		ft_lst_push_back(&context->sections, redir_list);
		iter = iter->next;
	}
	context->is_valid = 1;
}
