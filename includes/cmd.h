/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:51:12 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 19:54:07 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -----------------
// |  Definitions  |
// -----------------

#ifndef CMD_H
# define CMD_H

// ------------
// | Includes |
// ------------

# include <stdio.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include "core.h"
# include "ft_list.h"
# include "libft_x.h"
# include "xstring.h"
# include "parser.h"

/*
	Struct for the command line
*/
typedef struct s_cmd
{
	char	*path;
	char	**args;
	int		args_count;
	int		is_builtin;
}	t_cmd;

// -----------------------
// | Command & builtins  |
// -----------------------

t_cmd	*new_cmd(const char *line);
void	clear_cmd(t_cmd *cmd);
void	print_cmd(t_cmd *cmd, int fd);
char	*get_cmd_path(const char *cmd_name);
int		is_builtin(const char *path);

#endif
