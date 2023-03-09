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

void	close_section_files(void *content, size_t i, int isf, int isl)
{
	t_section_slice	*slice;
	t_section		*section

	(void) i;
	(void) isf;
	(void) isl;
	section = (t_section *) content;
	slice = (t_section_slice *) section->content;
	if (slice->type != REDIR_CMD)
	{
		close(slice->fd);
		if (slice->type == REDIR_HEREDOC)
			unlink(slice->str);
	}
	if (slice->str != NULL)
		free(slice->str);
}
