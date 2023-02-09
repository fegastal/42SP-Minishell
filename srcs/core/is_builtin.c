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
	size_t		i;

	iter = builtins;
	while (*iter != NULL)
	{
		i = 0;
		while (path[i] != '\0' && path[i] == (*iter)[i])
			i += 1;
		if (path[i] == (*iter)[i])
			return (1);
		iter++;
	}
	return (0);
}
