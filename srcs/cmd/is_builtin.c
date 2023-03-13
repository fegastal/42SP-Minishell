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

#include "builtins.h"

/*
	Checks that a string is one of the shell's supported built-in
	commands by comparing the string against an array of strings
	containing the names of the built-in commands.
*/
int	is_builtin(const char *name)
{
	static const char	*builtins[] = {
		"export", "pwd", "unset",
		"echo", "cd", "env", "exit",
		NULL
	};
	const char			**iter;
	size_t				i;

	iter = builtins;
	while (*iter != NULL)
	{
		i = 0;
		while (name[i] != '\0' && name[i] == (*iter)[i])
			i += 1;
		if (name[i] == (*iter)[i])
			return (1);
		iter++;
	}
	return (0);
}
