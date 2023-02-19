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

# define IS_EXPORT 1
# define IS_NOT_EXPORT 0

typedef enum	e_mode
{
	DEFAULT,
	DOUBLE_QUOTES,
	SINGLE_QUOTES
}	t_mode;

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

typedef struct	s_ev_node
{
	char	*name;
	char	*value;
	int		is_export;
}	t_ev_node;

typedef enum e_ev_code
{
	EV_ERROR,
	EV_UPDATE,
	EV_PUSH
}	t_ev_code;

t_core		g_core;

void		core_init(int argc, char *argv[], char *envp[]);
void		core_clear(void);

t_ev_node	*get_ev(const char *name);
int			set_ev(char *name, char *value, int is_export);
void		clear_ev(void *ev);
void 		rmv_ev(char const *name);
int			ev_name_is_valid(char const *name);

#endif
