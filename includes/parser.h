/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:27:39 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/01/26 11:27:39 by lsilva-q         ###   ########.fr       */
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

# include "libft_x.h"
# include "ft_list.h"
# include "stdio.h"

typedef enum	e_slice_modes
{
	SLCMODE_DEFAULT,
	SLCMODE_DOUBLE_QUOTES,
	SLCMODE_QUOTES
}	t_slice_modes;

typedef struct	s_slice
{
	char	*start;
	int		type;
}	t_slice;

typedef struct s_slicer
{
	char	*line;
	char	*chr;
	char	*tmp;
	int		mode;
	int		slice_type;
}	t_slicer;


// char	*expand_line(char *line);
t_ftlist	slice_line(char *line);

#endif
