/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:24:21 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/12/13 15:24:21 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <limits.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "ft_list.h"

# define ALL_TOKEN_CHARS " |$?'\"<>-"

typedef enum e_msg_code
{
	EV_ERROR,
	EV_UPDATE,
	EV_PUSH
}	t_msg_code;

typedef struct	s_ev_node
{
	char	*name;
	char	*value;
	int		is_export;
}	t_ev_node;

typedef struct	s_msh_core
{
	t_ftlist	ev_list;
}	t_msh_core;

typedef enum e_token_modes
{
	TKMODE_DEFAULT,
	TKMODE_STR_SINGLE,
	TKMODE_STR_DOUBLE,
}	t_token_modes;

// 00) TKTYPE_WHITESPACE,
// 01) TKTYPE_PIPE,
// 02) TKTYPE_DOLLAR,
// 03) TKTYPE_QUESTION_MARK,
// 04) TKTYPE_STR_SINGLE,
// 05) TKTYPE_STR_DOUBLE,
// 06) TKTYPE_ABRACK_LEFT,
// 07) TKTYPE_ABRACK_RIGHT,
// 08) TKTYPE_MINUS,
// 09) TKTYPE_END,
// 10) TKTYPE_INVALID
typedef enum e_token_types
{
	TKTYPE_WHITESPACE,
	TKTYPE_PIPE,
	TKTYPE_DOLLAR,
	TKTYPE_QUESTION_MARK,
	TKTYPE_STR_SINGLE,
	TKTYPE_STR_DOUBLE,
	TKTYPE_ABRACK_LEFT,
	TKTYPE_ABRACK_RIGHT,
	TKTYPE_MINUS,
	TKTYPE_END,
	TKTYPE_INVALID
}	t_token_types;

typedef struct	s_msh_token
{
	char	*ptr;
	int		type;
}	t_msh_token;

t_msh_core	g_core;

void		core_init(void);
void		core_loop(void);
void		clear_screen(void);
char		*get_prefix(void);
void		handle_signal_fork(void);
void		handle_signal(void);
char		*create_prompt(void);

// Environment Variables

t_ev_node	*get_ev(char *name);
int			set_ev(char *name, char *value, int is_export);

// Parser

int			get_token_type(char chr);
t_ftlist	tokenize(char *str);

#endif
