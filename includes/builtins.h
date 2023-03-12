/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:51:12 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 16:44:33 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "core.h"
# include "cmd.h"
# include "libft_x.h"
# include "error.h"

typedef struct s_echo
{
	int		find_flag;
	int		ignore_newline;
	char	*final_str;
}	t_echo;

int	call_builtin(t_cmd *cmd);
int	call_single_builtin(t_cmd *cmd);
int	builtin_unset(t_cmd *cmd);
int	builtin_echo(t_cmd *cmd);
int	builtin_exit(t_cmd *cmd);
int	builtin_pwd(t_cmd *cmd);
int	builtin_export(t_cmd *cmd);
int	builtin_env(t_cmd *cmd);
int	builtin_cd(t_cmd *cmd);

#endif
