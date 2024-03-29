/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:14:05 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/07 22:14:05 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

/*
	Returns the full path of a command specified by its name, 
	checking whether it is an absolute or relative path and,
	if not, looking for the path in the directories listed
	in the shell's PATH environment variable.
*/
char	*get_cmd_path(const char *cmd_name)
{
	char	**iter;
	char	*path;

	if (cmd_name == NULL)
		return (NULL);
	if (cmd_name[0] == '/' || cmd_name[0] == '.')
	{
		if (!access(cmd_name, X_OK))
			return (ft_strdup(cmd_name));
		return (NULL);
	}
	update_paths();
	if (g_core.paths == NULL)
		return (NULL);
	iter = g_core.paths;
	while (*iter != NULL)
	{
		path = ft_xstr_join("/", *iter, cmd_name);
		if (!access(path, X_OK))
			return (path);
		free(path);
		iter++;
	}
	return (NULL);
}
