/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:40:53 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/20 19:40:53 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_tokenizer	*tkn_init(const char *str, const char *tk_table)
{
	t_tokenizer	*tkn;

	tkn = malloc(sizeof(t_tokenizer));
	*tkn = (t_tokenizer){str, tk_table, 0};
	return (tkn);
}
