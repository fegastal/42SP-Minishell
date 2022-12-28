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

// # define EV_ERROR 0
// # define EV_SET 1
// # define EV_PUSH 2

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

#endif
