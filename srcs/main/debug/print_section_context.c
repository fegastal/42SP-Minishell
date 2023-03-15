/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_section_context.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:33:15 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 17:33:15 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_section_context(t_section_context *ctx, const char *prefix)
{
	if (ctx == NULL)
		return ;
	if (prefix != NULL)
		ft_putstr_fd((char *) prefix, 1);
	ft_putstr_fd("first_cmd: ", 1);
	if (ctx->first_cmd == NULL)
		ft_putstr_fd("NULL\n", 1);
	print_section_slice(ctx->first_cmd, NULL);
	ft_putstr_fd("last_infile: ", 1);
	if (ctx->last_infile == NULL)
		ft_putstr_fd("NULL\n", 1);
	print_section_slice(ctx->last_infile, NULL);
	ft_putstr_fd("last_outfile: ", 1);
	if (ctx->last_outfile == NULL)
		ft_putstr_fd("NULL\n", 1);
	print_section_slice(ctx->last_outfile, NULL);
}
