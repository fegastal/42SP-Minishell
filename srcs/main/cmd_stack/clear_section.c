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

void	clear_section(void *content)
{
	t_section	*section;

	section = (t_section *) content;
	if (section == NULL)
		return ;
	ft_lst_clear(section, clear_section_slice);
	free(section);
}

void	clear_section_slice(void *content)
{
	t_section_slice	*slice;

	slice = (t_section_slice *) content;
	if (slice == NULL)
		return ;
	if (slice->str != NULL)
		free(slice->str);
	free(slice);
}
