/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:55:54 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/12/31 10:55:54 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

// All valid characters to be used as tokens
# define VALID_TOKENS " |$?'\"<>-"

// Count of token characters (including START, END and INVALID)
# define TOKENS_COUNT 12

# include "ft_list.h"

/*
	Parse modes to detect context for tokens.
*/
typedef enum e_parse_modes
{
	TKMODE_DEFAULT,
	TKMODE_STR_SINGLE,
	TKMODE_STR_DOUBLE,
	TKMODE_END
}	t_parse_modes;

// 0. TKTYPE_WHITESPACE,
// 1. TKTYPE_PIPE,
// 2. TKTYPE_DOLLAR,
// 3. TKTYPE_QUESTION_MARK,
// 4. TKTYPE_STR_SINGLE,
// 5. TKTYPE_STR_DOUBLE,
// 6. TKTYPE_ABRACK_LEFT,
// 7. TKTYPE_ABRACK_RIGHT,
// 8. TKTYPE_MINUS,
// 9. TKTYPE_START,
// 10. TKTYPE_END,
// 11. TKTYPE_INVALID
typedef enum e_token_types
{
	TKTYPE_WHITESPACE,
	TKTYPE_PIPE,
	TKTYPE_DOLLAR,
	TKTYPE_QUESTION_MARK,
	TKTYPE_STR_SINGLE,
	TKTYPE_STR_DOUBLE,
	TKTYPE_ABRACK_LEFT,
	TKTYPE_ABRACK_RIGHT,
	TKTYPE_MINUS,
	TKTYPE_START,
	TKTYPE_END,
	TKTYPE_INVALID
}	t_token_types;

/*
	Basic token struct, to be used in linked lists. Contains a pointer (ptr)
	to the position of token in string, and the type (type) of the token.
*/
typedef struct	s_msh_token
{
	char	*ptr;
	int		type;
}	t_msh_token;

/*
	Struct returned from tokenization. Contains all tokens (tokens), stored in
	an array with size TOKENS_COUNT, where each item is an unique token
	type (indexes are based on t_token_types enum). Also contains a pointer to
	the original string (str).
*/
typedef struct	s_msh_tknz
{
	t_ftlist	*tokens;
	t_ftlist	modes;
	char		*str;
}	t_msh_tknz;

int			get_token_type(char chr);
char		*get_token_name(int token_type);
t_msh_tknz	*tokenize(char *str); // Alterar para const
void		clear_tokens(t_msh_tknz **tokens);

#endif
