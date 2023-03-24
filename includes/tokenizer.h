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
*	Tokenization struct.
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

// Main functions

t_tokenizer			*tkn_tokenize(const char *str, const char *tk_table);

// last_mode: DEFAULT
//      Q         D        Q         D
// echo "abobrinha" | ls > "file|.txt"
//      ^         ^ ^    ^      ^
//      0         0 2    3      2
//
// tokens: { "'|>< }
// codes:  { 01234 }
// MEU_ARQUIVO.c:
//
// t_tokenizer	*tkn;
//
// tkn = tkn_tokenize("echo \"abobrinha\" | ls > file.txt", "\"'|><");


// Iterator functions

t_token				*tknext(t_tokenizer *tkn, t_token *start, int code);

// tk = tknext(tkn, NULL, tkcode(tkn, '"'))
// tk = tknext(tkn, tk, tkcode(tkn, '"'))
// tk = tknext(tkn, tk, tkcode(tkn, '|'))

t_token				*tkprev(t_tokenizer *tkn, t_token *start, int code);

// Utility functions

int					tkcode(t_tokenizer *tkn, char chr);
int					tkcmp(t_token *tk1, t_token *tk2);
int					tkcode_cmp(t_token *tk, int code);

#endif
