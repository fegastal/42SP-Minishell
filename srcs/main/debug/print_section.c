/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_section.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:04:35 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 17:04:35 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lst_print_section(void *content, size_t i, int isf, int isl);

void	print_section(t_section *section, const char *prefix)
{
	if (section == NULL)
		return ;
	if (prefix != NULL)
		ft_putstr_fd((char *) prefix, 1);
	ft_lst_func_apply(section, lst_print_section);
}

static void	lst_print_section(void *content, size_t i, int isf, int isl)
{
	t_section_slice	*slice;

	(void) i;
	(void) isf;
	(void) isl;
	slice = (t_section_slice *) content;
	print_section_slice(slice, NULL);
}
