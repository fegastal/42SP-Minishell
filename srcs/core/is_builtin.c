/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:41:16 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/01/10 13:41:16 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(const char *path)
{
	static const char	*builtins[] = {
		"export", "pwd", "unset",
		"echo", "cd", "env", "exit",
		NULL
	};
	const char	**iter;

	iter = builtins;
	while (*iter != NULL)
	{
		if (!ft_strncmp(*iter, path, ft_strlen(*iter)))
			return (1);
		iter++;
	}
	return (0);
}
