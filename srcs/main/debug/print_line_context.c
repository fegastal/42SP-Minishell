/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line_context.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:01:24 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/14 15:01:24 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lst_print_section_list(void *content, size_t i, int isf, int isl);

void	print_line_context(t_line_context *context, const char *prefix)
{
	if (context == NULL)
		return ;
	if (prefix != NULL)
		ft_putstr_fd((char *) prefix, 1);
	ft_putstr_fd("# Line context:\n", 1);
	ft_putstr_fd("sections: [", 1);
	if (context->sections.size > 0)
		ft_putchar_fd('\n', 1);
	ft_lst_func_apply(&context->sections, lst_print_section_list);
	ft_putstr_fd("]\nis_valid: ", 1);
	ft_putnbr_fd(context->is_valid, 1);
	ft_putstr_fd("\n#\n", 1);
}

static void	lst_print_section_list(void *content, size_t i, int isf, int isl)
{
	t_section	*section;
	char		*index;
	char		*prefix;

	(void) i;
	(void) isf;
	(void) isl;
	section = (t_section *) content;
	index = ft_itoa(i);
	prefix = ft_xstr_mjoin("", 3, "Section ", index, ":\n");
	print_section(section, prefix);
	free(index);
	free(prefix);
}
