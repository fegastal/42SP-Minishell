/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:04:14 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 20:33:44 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -----------------
// |  Definitions  |
// -----------------

#ifndef CORE_H
# define CORE_H

# define IS_RUNNING 1
# define IS_NOT_RUNNING 0

// ------------
// | Includes |
// ------------

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "ft_list.h"
# include "libft_x.h"
# include "xstring.h"
# include "error.h"

typedef enum e_mode
{
	DEFAULT,
	DOUBLE_QUOTES,
	SINGLE_QUOTES
}	t_mode;

typedef enum e_redirs
{
	REDIR_NONE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
	REDIR_CMD
}	t_redirs;

/*
	Types to specify fd_in and fd_out from g_core
*/
typedef enum e_redir_fd_type
{
	FD_REDIR_STD,
	FD_REDIR_FILE,
	FD_REDIR_PIPE
}	t_redir_fd_type;

/*
	**can_proceed** is used to check if the current command can be
	executed, based on the last command's status.
	This is used to check syntax errors coming from the previous pipe.

	**fd_in** & **fd_out** are used only when redirecting
	from/to a file.
*/
typedef struct s_core
{
	t_ftlist		ev_list;
	int				is_running;
	int				can_proceed;
	int				last_pid;
	int				last_status;
	int				pipe[2];
	int				std_in;
	int				std_out;
	int				fd_in;
	int				fd_out;
	t_redir_fd_type	fd_in_type;
	t_redir_fd_type	fd_out_type;
	int				argc;
	char			**argv;
	char			**envp;
	char			**paths;
}	t_core;

/*
	Struct with the environment
	variable data (name and value)
*/
typedef struct s_ev
{
	const char	*name;
	const char	*value;
}	t_ev;

/*
	Struct to return the status
	of the environment variable
*/
typedef enum e_ev_status
{
	EV_ERROR,
	EV_UPDATE,
	EV_PUSH
}	t_ev_status;

/*
	Struct to use in split (core)
*/
typedef struct s_splitter
{
	char const	*line;
	char const	*iter;
	char const	*last_found;
	t_ftlist	list;
	t_mode		mode;
	void		*aux;
}	t_splitter;

/*
	Global core variable
*/
extern t_core		g_core;

// ------------------
// | Core functions |
// ------------------

void		core_init(int argc, char *argv[], char *envp[]);
void		core_clear(void);

// -------------------------------------
// | Function of environment variables |
// -------------------------------------

t_ev		*get_ev(const char *name);
char		*get_ev_value(const char *name);
t_ev_status	set_ev(char *name, char *value);
void		clear_ev(void *ptr);
void		rmv_ev(const char *name);

// ---------------------
// |  Utils Functions  |
// ---------------------

int			ev_name_is_valid(const char *name);
char		*get_str_no_quotes(const char *str);
char		**split_ev_line(const char *line);
void		update_envp(void);
void		clear_envp(void);
void		clear_paths(void);
void		update_paths(void);

// --------------------
// |  Error handling  |
// --------------------

int			syntax_error(void);
int			file_permission_error(void);
int			wrong_builtin_args_error(void);
int			home_not_set_error(void);
int			no_such_file_or_dir_error(void);
int			not_a_valid_identifier_error(void);
int			numeric_arg_required_error(void);

#endif
