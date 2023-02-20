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

// static char	**cmd_line_split(const char *line, int *size);
static void	check_mode_default(t_splitter *parser);
static void	check_mode_double_quotes(t_splitter *parser);
static void	check_mode_single_quotes(t_splitter *parser);
static void	end_func(t_splitter *parser);

t_cmd	*new_cmd(const char *line)
{
	t_ftlist	args_list;
	t_cmd		*cmd;
	char		*tmp;

	if (line == NULL)
		return (NULL);
	cmd = malloc(sizeof(t_cmd));
	tmp = ft_strtrim(line, " ");
	args_list = parse_context(tmp, (t_context){
			.def_func = check_mode_default,
			.dquotes_func = check_mode_double_quotes,
			.squotes_func = check_mode_single_quotes,
			.end_func = end_func
		});
	cmd->args = (char **) ft_lst_toarray(&args_list);
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
		if (*chr == '"')
			parser->mode = DOUBLE_QUOTES;
		else if (*chr == '\'')
			parser->mode = SINGLE_QUOTES;
		else if (*chr == ' ')
		{
			ft_lst_push_back(&(parser->list),
				ft_strndup(parser->last_found, chr - parser->last_found));
			parser->last_found = NULL;
		}
	}
}

static void	check_mode_double_quotes(t_splitter *parser)
{
	const char	*chr;

	chr = parser->iter;
	if (*chr == '"')
	{
		ft_lst_push_back(&(parser->list),
			ft_strndup(parser->last_found, chr - parser->last_found + 1));
			// ft_strndup(parser->last_found + 1, chr - parser->last_found - 1));
		parser->last_found = NULL;
		parser->mode = DEFAULT;
	}
}

static void	check_mode_single_quotes(t_splitter *parser)
{
	const char	*chr;

	chr = parser->iter;
	if (*chr == '\'')
	{
		ft_lst_push_back(&(parser->list),
			ft_strndup(parser->last_found + 1, chr - parser->last_found - 1));
		parser->last_found = NULL;
		parser->mode = DEFAULT;
	}
}

static void	end_func(t_splitter *ps)
{
	if (splitter->last_found != NULL)
		ft_lst_push_back(&(splitter.list), ft_strdup(splitter.last_found));
}
