/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_such_file_or_dir_error.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:54:53 by fgastal-          #+#    #+#             */
/*   Updated: 2023/03/14 22:54:53 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

/*
	Displays an error message indicating that the file
	or directory does not exist.
*/
int	no_such_file_or_dir_error(void)
{
	error(ERR_NO_SUCH_FILE_OR_DIR, NULL);
	g_core.last_status = ERR_NO_SUCH_FILE_OR_DIR;
	g_core.can_proceed = 0;
	return (ERR_NO_SUCH_FILE_OR_DIR);
}
