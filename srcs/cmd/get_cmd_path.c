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

char	*get_cmd_path(const char *cmd_name, char **paths)
{
	char	**iter;
	char	*path;

	if (!cmd_name || !paths)
		return (NULL);
	iter = paths;
	while (iter != NULL)
	{
		path = ft_xstr_join("/", 2, *iter, cmd_name);
		if (!access(path, X_OK))
			return (path);
		free(path);
		iter++;
	}
	return (NULL);
}
