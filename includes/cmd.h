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

typedef struct	s_cmd
{
	char	*path;
	char	**args;
	int		args_count;	// Revisar usos
}	t_cmd;

typedef struct	s_cmd_splitter
{
	char const	*line;
	char const	*iter;
	char const	*last_found;
	t_ftlist	cmd_list;
	t_mode		mode;
}	t_cmd_splitter;

t_cmd	*new_cmd(const char *line);
void	clear_cmd(t_cmd *cmd);
void	print_cmd(t_cmd *cmd);
char	*get_cmd_path(const char *cmd_name);

#endif
