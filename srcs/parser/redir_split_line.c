/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_split_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:47:12 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/16 21:27:52 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		default_mode(t_splitter *sp);
static void		end_func(t_splitter *sp);
static t_redirs	get_new_type(t_splitter *sp, t_redirs last_type);
static int		can_add(t_splitter *sp, t_redirs last_type);

/*
	Takes an input line and returns a chained list of redirects,
	using the parse_context function with a specific context to parse
	the standard mode and the double-quoted mode.
*/
t_ftlist	redir_split_line(const char *line)
{
	t_ftlist	redirs;
	t_redirs	last_type;

	if (line == NULL || ft_xstr_match_set(line, " ") || line[0] == '\0')
		return ((t_ftlist){0});
	last_type = REDIR_NONE;
	redirs = parse_context(line, (t_context){
			.def_func = default_mode,
			.dquotes_func = NULL,
			.squotes_func = NULL,
			.end_func = end_func
		}, &last_type, " <>");
	return (redirs);
}

static void	default_mode(t_splitter *sp)
{
	t_redir_slice	*slice;
	t_redirs		*last_type;
	t_redirs		new_type;

	last_type = (t_redirs *) sp->aux;
	if (sp->last_found == NULL && !ft_strchr(" <>", *sp->iter))
		sp->last_found = sp->iter;
	if (*sp->iter == '"')
		sp->mode = DOUBLE_QUOTES;
	else if (*sp->iter == '\'')
		sp->mode = SINGLE_QUOTES;
	new_type = get_new_type(sp, *last_type);
	if (can_add(sp, *last_type))
	{
		slice = new_redir_slice(*last_type, -1,
				ft_strndup(sp->last_found, sp->iter - sp->last_found));
		ft_xstr_supplant(&slice->str, ft_strtrim(slice->str, " "));
		ft_xstr_supplant(&slice->str, get_str_no_quotes(slice->str));
		ft_lst_push_back(&sp->list, slice);
		sp->last_found = NULL;
	}
	*last_type = new_type;
}

static void	end_func(t_splitter *sp)
{
	t_redir_slice	*slice;
	t_redirs		*last_type;

	last_type = (t_redirs *) sp->aux;
	if (sp->last_found != NULL)
	{
		slice = new_redir_slice(*last_type, -1,
				ft_strdup(sp->last_found));
		ft_xstr_supplant(&slice->str, ft_strtrim(slice->str, " "));
		ft_xstr_supplant(&slice->str, get_str_no_quotes(slice->str));
		ft_lst_push_back(&sp->list, slice);
	}
	else if (*last_type != REDIR_NONE && *last_type != REDIR_CMD)
	{
		slice = new_redir_slice(*last_type, -1, NULL);
		ft_lst_push_back(&sp->list, slice);
	}
}

static t_redirs	get_new_type(t_splitter *sp, t_redirs last_type)
{
	t_redirs	new_type;

	new_type = last_type;
	if (*sp->iter == ' ' && sp->last_found != NULL)
	{
		if (last_type != REDIR_CMD && last_type != REDIR_NONE)
			new_type = REDIR_CMD;
	}
	else if (*sp->iter == '>')
	{
		new_type = REDIR_OUT;
		if (last_type == REDIR_OUT)
			new_type = REDIR_APPEND;
	}
	else if (*sp->iter == '<')
	{
		new_type = REDIR_IN;
		if (last_type == REDIR_IN)
			new_type = REDIR_HEREDOC;
	}
	else if (last_type == REDIR_NONE)
		new_type = REDIR_CMD;
	return (new_type);
}

static int	can_add(t_splitter *sp, t_redirs last_type)
{
	if (sp->last_found == NULL || last_type == REDIR_NONE)
		return (0);
	else if (sp->last_found[0] == '\0')
		return (0);
	else if (*sp->iter == ' ')
	{
		if (last_type != REDIR_CMD && last_type != REDIR_NONE)
			return (1);
	}
	else if (*sp->iter == '>' && last_type != REDIR_OUT)
		return (1);
	else if (*sp->iter == '<' && last_type != REDIR_IN)
		return (1);
	return (0);
}
