/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:27:39 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 16:46:22 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// # define DEFAULT_TOKENS " |$?'\"<>-"
// # define DOUBLE_QUOTES_TOKENS "$\""
// # define QUOTES_TOKENS "'"
// DEFAULT_TOKENS ("$')

# define SLICE_TYPE_NON_VAR 0
# define SLICE_TYPE_VAR 1

# include <stdio.h>
# include "core.h"
# include "libft_x.h"
# include "ft_list.h"
# include "xstring.h"

typedef enum e_slice_type
{
	NON_VAR = 0,
	VAR = 1
}	t_slice_type;

typedef struct s_slice
{
	char			*start;
	t_slice_type	type;
}	t_slice;

typedef struct s_redir_slice
{
	char	*str;
	int		type;
	int		fd;
}	t_redir_slice;

typedef struct s_expander
{
	t_slice_type	*last_type;
	t_slice_type	new_type;
	t_slice			*slice;
	int				can_add;
}	t_expander;

/*
	void	def_func(t_splitter *s);
	void	dquotes_func(t_splitter *s);
	void	squotes_func(t_splitter *s);
	void	end_func(t_splitter *s);
*/
typedef struct s_context
{
	void	(*def_func)(t_splitter *);
	void	(*dquotes_func)(t_splitter *);
	void	(*squotes_func)(t_splitter *);
	void	(*end_func)(t_splitter *);
}	t_context;

char		*expand_line(char const *line);
t_ftlist	parse_context(const char *line, t_context context, void *aux);
t_ftlist	pipe_split_line(const char *line);
t_ftlist	redir_split_line(const char *line);

#endif
