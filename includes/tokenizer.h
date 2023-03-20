/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:04:12 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/20 19:04:12 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "libft_x.h"
# include "ft_list.h"

// List of tokens
typedef t_ftlist	t_tklist;

// Token struct
typedef struct s_token
{
	const char	*ptr;
	int			code;
}	t_token;

/*
*	Return struct generated from tokenization.
*	- str: string to be tokenized.
*	- tk_table: table of tokens to be used.
*	- tokens: list of tokens generated.
*/
typedef struct s_tokenizer
{
	const char	*str;
	const char	*tk_table;
	t_tklist	*tokens;
}	t_tokenizer;

int			tkcode(t_tokenizer *tkn, char chr);
t_tokenizer	*tkn_init(const char *str, const char *tk_table);
t_tokenizer	*tkn_tokenize(const char *str, const char *tk_table);

#endif
