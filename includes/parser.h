/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:27:39 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 20:48:52 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -----------------
// |  Definitions  |
// -----------------

#ifndef PARSER_H
# define PARSER_H

# define SLICE_TYPE_NON_VAR 0
# define SLICE_TYPE_VAR 1

// ------------
// | Includes |
// ------------

# include <stdio.h>
# include "core.h"
# include "libft_x.h"
# include "ft_list.h"
# include "xstring.h"

/*
	Struct with return settings
	for "variable" or "non-variable"
*/
typedef enum e_slice_type
{
	NON_VAR = 0,
	VAR = 1
}	t_slice_type;

/*
	Struct with slice "start" and "type" variables
*/
typedef struct s_slice
{
	char			*start;
	t_slice_type	type;
}	t_slice;

/*
	Struct with slice redirection variables
*/
typedef struct s_redir_slice
{
	char	*str;
	int		type;
	int		fd;
}	t_redir_slice;

/*
	Struct with variables to do the expansion
*/
typedef struct s_expander
{
	t_slice_type	*last_type;
	t_slice_type	new_type;
	t_slice			*slice;
	int				can_add;
}	t_expander;

/*
	Struct with variables to do the context
*/
typedef struct s_context
{
	void	(*def_func)(t_splitter *);
	void	(*dquotes_func)(t_splitter *);
	void	(*squotes_func)(t_splitter *);
	void	(*end_func)(t_splitter *);
}	t_context;

/*
	Struct with variables to do the expansion
	and the parsing of the line
*/
char			*expand_line(char const *line);
t_ftlist		parse_context(const char *line, t_context context, void *aux,
					const char *to_first_ignore);
char			*expand_file_path(const char *filepath);

/*
	Struct with variables to do the split of the line
*/
t_ftlist		pipe_split_line(const char *line);
t_ftlist		redir_split_line(const char *line);
t_redir_slice	*new_redir_slice(int type, int fd, char *str);

void			print_slice(t_slice *slice, const char *prefix);
int				is_valid_ev_char_on_splitter(t_splitter *sp);

#endif
