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

static char	**cmd_line_split(const char *line);
static void	check_mode_default(t_cmd_splitter *parser);
static void	check_mode_double_quotes(t_cmd_splitter *parser);
static void	check_mode_single_quotes(t_cmd_splitter *parser);

t_cmd	*new_cmd(const char *line, char **paths)
{
	t_cmd	*cmd;
	char	*tmp;

	if (line == NULL)
		return (NULL);
	cmd = malloc(sizeof(t_cmd));
	tmp = ft_strtrim(line, " ");
	cmd->path = get_cmd_path(tmp, paths);
	cmd->args = cmd_line_split(tmp);
	free(tmp);
	return (cmd);
}

static char	**cmd_line_split(char const *line)
{
	t_cmd_splitter	parser;
	char			**array;

	parser.line = line;
	parser.iter = line;
	parser.last_found = NULL;
	ft_lst_init(&(parser.cmd_list));
	parser.mode = DEFAULT;
	while (*(parser.iter) != '\0')
	{
		if (parser.mode == DEFAULT)
			check_mode_default(&parser);
		else if (parser.mode == DOUBLE_QUOTES)
			check_mode_double_quotes(&parser);
		else if (parser.mode == SINGLE_QUOTES)
			check_mode_single_quotes(&parser);
		parser.iter++;
	}
	ft_lst_push_back(&(parser.cmd_list), ft_strdup(parser.last_found));
	array = (char **) ft_lst_toarray(&(parser.cmd_list));
	ft_lst_clear(&(parser.cmd_list), NULL);
	return (array);
}

static void	check_mode_default(t_cmd_splitter *parser)
{
	char const	*chr;

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
		if (*chr == ' ')
		{
			ft_lst_push_back(&(parser->cmd_list),
				ft_strndup(parser->last_found, chr - parser->last_found));
			parser->last_found = NULL;
		}
	}
}

static void	check_mode_double_quotes(t_cmd_splitter *parser)
{
	char const	*chr;

	chr = parser->iter;
	if (*chr == '"')
	{
		ft_lst_push_back(&(parser->cmd_list),
			ft_strndup(parser->last_found + 1, chr - parser->last_found - 1));
		parser->last_found = NULL;
		parser->mode = DEFAULT;
	}
}

static void	check_mode_single_quotes(t_cmd_splitter *parser)
{
	char const	*chr;

	chr = parser->iter;
	if (*chr == '\'')
	{
		ft_lst_push_back(&(parser->cmd_list),
			ft_strndup(parser->last_found + 1, chr - parser->last_found - 1));
		parser->last_found = NULL;
		parser->mode = DEFAULT;
	}
}
