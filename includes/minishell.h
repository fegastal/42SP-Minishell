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
# include "core.h"
# include "ft_list.h"
# include "libft_x.h"
# include "xstring.h"
# include "parser.h"
# include "cmd.h"
# include "builtins.h"

// This is a list of t_section
typedef t_ftlist		t_section_list;

// This is a list of t_section_slice
typedef t_ftlist		t_section;

// This is a list of char * (string)
typedef t_ftlist		t_string_list;

// This is an alias for t_redir_slice
typedef t_redir_slice	t_section_slice;

// Context struct containing a parsed line and a validity flag
typedef struct s_line_context
{
	t_section_list	sections;
	int				is_valid;
}	t_line_context;

typedef struct s_cmd_executor
{
	t_cmd	*cmd;
	int		last_pipe_in;
	pid_t	pid;
	int		is_first;
	int		is_last;
	int		wstatus;
}	t_cmd_executor;

typedef struct s_section_context
{
	t_section_slice	*first_cmd;
	t_section_slice	*last_infile;
	t_section_slice	*last_outfile;
}	t_section_context;

void					main_loop(void);
void					clear_screen(void);
char					*get_prefix(void);
void					handle_signal_fork(void);
void					handle_signal(void);
char					*create_prompt(void);

// ------------------------
// | Line & cmd execution |
// ------------------------

char					*get_tmp_file_name(void);
void					exec_cmd(t_cmd *cmd, int is_first, int is_last);
void					exec_line(const char *line);
t_line_context			get_line_context(const char *line);
t_section_context		open_section_files(t_section *section);
void					close_section_files(void *content, size_t i,
							int isf, int isl);
void					clear_section(void *content);
void					clear_section_slice(void *content);

#endif
