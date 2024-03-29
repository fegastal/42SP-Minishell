/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_section_files.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:16:45 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/08 21:16:45 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Closes open files during the execution of a shell command.
*/
void	close_section_files(void *content, size_t i, int isf, int isl)
{
	t_section_slice	*slice;

	(void) i;
	(void) isf;
	(void) isl;
	slice = (t_section_slice *) content;
	if (slice->type != REDIR_CMD)
	{
		if (slice->fd != -1)
			close(slice->fd);
		if (slice->type == REDIR_HEREDOC)
			unlink(slice->str);
	}
}
