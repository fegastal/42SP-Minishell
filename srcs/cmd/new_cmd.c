/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:56:34 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/07 21:56:34 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static void	check_mode_default(t_splitter *parser);
static void	check_mode_quotes(t_splitter *parser);
static void	check_mode_end(t_splitter *parser);
static void	push_arg_to_parser_list(t_splitter *parser, char *arg);

/*
	The new_cmd function creates a t_cmd structure that represents
	a command to be executed by the shell.
*/
t_cmd	*new_cmd(const char *line)
{
	t_ftlist	args_list;
	t_cmd		*cmd;
	char		*tmp;

	if (line == NULL)
		return (NULL);
	cmd = malloc(sizeof(t_cmd));
	tmp = ft_strtrim(line, " ");
	if (tmp == NULL || !ft_strcmp(tmp, " ") || tmp[0] == '\0')
		return (NULL);
	args_list = parse_context(tmp, (t_context){
			.def_func = check_mode_default,
			.dquotes_func = check_mode_quotes,
			.squotes_func = check_mode_quotes,
			.end_func = check_mode_end
		}, NULL, NULL);
	cmd->args = (char **) ft_lst_toarray(&args_list);
	cmd->args_count = args_list.size;
	cmd->is_builtin = is_builtin(cmd->args[0]);
	ft_lst_clear(&args_list, NULL);
	cmd->path = get_cmd_path(cmd->args[0]);
	free(tmp);
	return (cmd);
}

static void	check_mode_default(t_splitter *parser)
{
	const char	*chr;

	chr = parser->iter;
	if (parser->last_found == NULL && *chr != ' ')
	{
		if (*chr == '"')
			parser->mode = DOUBLE_QUOTES;
		else if (*chr == '\'')
			parser->mode = SINGLE_QUOTES;
		parser->last_found = parser->iter;
	}
	else if (parser->last_found != NULL)
	{
		if (ft_strchr(" \"'", *chr))
		{
			push_arg_to_parser_list(parser,
				ft_strndup(parser->last_found, chr - parser->last_found));
			if (*chr == ' ')
				parser->last_found = NULL;
			else
				parser->last_found = parser->iter;
		}
		if (*chr == '"')
			parser->mode = DOUBLE_QUOTES;
		else if (*chr == '\'')
			parser->mode = SINGLE_QUOTES;
	}
}

static void	check_mode_quotes(t_splitter *parser)
{
	const char	*chr;

	chr = parser->iter;
	if ((parser->mode == SINGLE_QUOTES && *chr == '\'')
		|| (parser->mode == DOUBLE_QUOTES && *chr == '"'))
	{
		push_arg_to_parser_list(parser,
			ft_strndup(parser->last_found + 1, chr - parser->last_found - 1));
		parser->last_found = NULL;
		parser->mode = DEFAULT;
	}
}

static void	check_mode_end(t_splitter *parser)
{
	const char	*chr;
	char		*tmp;

	chr = parser->iter;
	if (parser->last_found != NULL)
	{
		if (parser->mode == SINGLE_QUOTES || parser->mode == DOUBLE_QUOTES)
		{
			tmp = ft_strndup(parser->last_found + 1,
					chr - parser->last_found - 1);
		}
		else
			tmp = ft_strdup(parser->last_found);
		push_arg_to_parser_list(parser, tmp);
		parser->last_found = NULL;
	}
}

static void	push_arg_to_parser_list(t_splitter *parser, char *arg)
{
	const char	*prev_char;
	char		*last_str;
	char		*tmp;

	prev_char = parser->last_found - 1;
	if (prev_char < parser->line || parser->list.back == NULL)
		return ((void) ft_lst_push_back(&(parser->list), arg));
	last_str = parser->list.back->content;
	if (*prev_char == ' ')
		return ((void) ft_lst_push_back(&(parser->list), arg));
	tmp = ft_xstr_append(last_str, arg);
	free(last_str);
	ft_lst_set(&(parser->list), parser->list.size - 1, tmp);
	free(arg);
}
