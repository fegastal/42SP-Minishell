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

# include "cmd.h"
# include "libft_x.h"

int	is_builtin(const char *path);
void call_builtin(t_cmd *cmd);

#endif