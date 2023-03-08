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

typedef struct	s_line_context
{
	t_ftlist	sections;
	const int	is_valid;
}	t_line_context;

typedef struct	s_cmd_executor
{
	t_cmd	*cmd;
	int		last_pipe_in;
	pid_t	pid;
	// int		fd_in;
	// int		fd_out;
	int		is_first;
	int		is_last;
	int		wstatus;
}	t_cmd_executor;

typedef struct	s_redir_context
{
	t_redir_slice	*first_cmd;
	t_redir_slice	*last_infile;
	t_redir_slice	*last_outfile;
}	t_redir_context;

void	main_loop(void);
void	clear_screen(void);
char	*get_prefix(void);
void	handle_signal_fork(void);
void	handle_signal(void);
char	*create_prompt(void);
void	exec_line(const char *line);
void 	exec_cmd(t_cmd *cmd, int is_first, int is_last);
char	*get_tmp_file_name(void);

#endif
