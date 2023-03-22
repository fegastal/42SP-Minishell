/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_slice_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:15:10 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/22 18:15:10 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	lst_print_slice_list(void *content, size_t i, int isf, int isl);

void	print_slice_list(t_ftlist *slices, const char *prefix)
{
	if (slices == NULL)
		return ;
	if (prefix != NULL)
		ft_putstr_fd((char *) prefix, 1);
	ft_lst_func_apply(slices, lst_print_slice_list);
}

static void	lst_print_slice_list(void *content, size_t i, int isf, int isl)
{
	t_slice	*slice;

	(void) i;
	(void) isf;
	(void) isl;
	slice = (t_slice *) content;
	print_slice(slice, NULL);
}
