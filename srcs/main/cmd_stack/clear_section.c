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

/*
	Frees the memory allocated to a section
	(represented by a chained list of t_section_slice).
*/
void	clear_section(void *content)
{
	t_section	*section;

	section = (t_section *) content;
	if (section == NULL)
		return ;
	ft_lst_clear(section, clear_section_slice);
	free(section);
}

/*
	Deallocates memory used by an element in a linked
	list that contains information about a slice of
	a command section.
*/
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
