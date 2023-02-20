/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:51:12 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/07 21:51:12 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "core.h"
# include "cmd.h"
# include "libft_x.h"

typedef struct	s_echo
{
	int		find_flag;
	int		ignore_newline;
	char	*final_str;
}	t_echo;

int		is_builtin(const char *path);
void	call_builtin(t_cmd *cmd);
void	builtin_unset(t_cmd *cmd);
void	builtin_echo(t_cmd *cmd);
void	builtin_exit(t_cmd *cmd);
void	builtin_pwd(void);
void	builtin_export(t_cmd *cmd);
void	builtin_env(t_cmd *cmd);
void	builtin_cd(t_cmd *cmd);

#endif
