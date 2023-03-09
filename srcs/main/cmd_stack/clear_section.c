/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_section.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:14:05 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/08 21:14:05 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_section_slice(void *content);

void	clear_section(t_section *section)
{
	ft_lst_clear(section, clean_section_slice);
	free(section);
}

static void	clean_section_slice(void *content)
{
	t_section_slice	*slice;

	slice = (t_section_slice *) content;
	if (slice->str != NULL)
		free(slice->str);
	free(slice);
}
