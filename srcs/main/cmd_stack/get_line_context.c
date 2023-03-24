/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_context.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:14:12 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 16:49:46 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_invalid_slice(void *content, void *new_content);
static void	populate_section(t_line_context *context, t_string_list *pipe_list);

/*
	This function builds a t_line_context struct from a line and returns it.
	The returned context have the following properties:
		- is_valid: 1 if the line is valid, 0 otherwise
		- sections: a list of t_section, each t_section is a list of
			t_section_slice
*/
t_line_context	get_line_context(const char *line)
{
	t_line_context	context;
	t_string_list	pipe_list;

	context = (t_line_context){0};
	if (ft_xstr_match_set(line, " \"\'"))
	{
		context.is_valid = 0;
		return (context);
	}
	pipe_list = pipe_split_line(line);
	context.sections = (t_section_list){0};
	populate_section(&context, &pipe_list);
	if (!context.is_valid)
		ft_lst_clear(&context.sections, clear_section);
	ft_lst_clear(&pipe_list, free);
	return (context);
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

static void	populate_section(t_line_context *context, t_string_list *pipe_list)
{
	t_ftnode	*iter;
	t_section	*section;

	iter = pipe_list->front;
	while (iter != NULL)
	{
		section = malloc(sizeof(t_section));
		*section = redir_split_line((const char *) iter->content);
		if (ft_lst_find(section, NULL, is_invalid_slice) || section->size == 0)
		{
			clear_section(section);
			context->is_valid = 0;
			return ;
		}
		ft_lst_push_back(&context->sections, section);
		iter = iter->next;
	}
	context->is_valid = 1;
}
