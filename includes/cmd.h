/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:51:12 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/07 21:51:12 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <stdio.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include "core.h"
# include "ft_list.h"
# include "libft_x.h"
# include "xstring.h"
# include "parser.h"

typedef struct	s_cmd
{
	char	*path;
	char	**args;
	int		args_count;	// Revisar usos
	int		is_builtin;
}	t_cmd;

t_cmd	*new_cmd(const char *line);
void	clear_cmd(t_cmd *cmd);
void	print_cmd(t_cmd *cmd);
char	*get_cmd_path(const char *cmd_name);
int		is_builtin(const char *path);

#endif
