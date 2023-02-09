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
# include "ft_list.h"
# include "libft_x.h"
# include "macros.h"

typedef struct	s_cmd
{
	char	*path;
	char	**args;
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
char	*get_cmd_path(const char *cmd_name, char **paths);

#endif