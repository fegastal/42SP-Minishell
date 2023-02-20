/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:04:14 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/16 09:04:14 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "ft_list.h"
# include "libft_x.h"
# include <stdio.h>

typedef enum	e_mode
{
	DEFAULT,
	DOUBLE_QUOTES,
	SINGLE_QUOTES
}	t_mode;

typedef enum	e_redirs
{
	REDIR_NONE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}	t_redirs;

typedef struct	s_core
{
	t_ftlist	ev_list;
	int			last_pid;
	int			last_status;
	int			argc;
	char		**argv;
	char		**envp;
	char		**paths;
}	t_core;

typedef struct	s_ev
{
	const char	*name;
	const char	*value;
}	t_ev;

typedef enum e_ev_status
{
	EV_ERROR,
	EV_UPDATE,
	EV_PUSH
}	t_ev_status;

typedef struct	s_splitter
{
	char const	*line;
	char const	*iter;
	char const	*last_found;
	t_ftlist	list;
	t_mode		mode;
}	t_splitter;

t_core		g_core;

void		core_init(int argc, char *argv[], char *envp[]);
void		core_clear(void);

t_ev		*get_ev(const char *name);
t_ev_status	set_ev(const char *name, const char *value);
void		clear_ev(void *ptr);
void 		rmv_ev(const char *name);
int			ev_name_is_valid(const char *name);
char		**split_ev_line(const char *line);

#endif
