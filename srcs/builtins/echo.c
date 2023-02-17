/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:41:16 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/01/10 13:41:16 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	echo [-neE] [arg ...]
	Display the ARGs, separated by a single space character and followed by a
	newline, on the standard output.
	-n	do not append a newline
*/

#include "builtins.h"

void echo(t_cmd *cmd)
{
	char	**iter;
	t_echo	e;

	e.find_flag = 1;
	e.ignore_newline = 0;
	e.final_str = ft_strdup("");
	iter = cmd->args + 1;
	if ((*iter)[0] == '-')
	{
		if
	}

// echo -E "dhuda" -n "ddjid"

// set_flags -> percorre todas as strings do cmd,
// e procura por flags, setando na struct t_echo
// passada por parâmetro

// ft_strchr -> utilizar para validar se todos os
// caracteres da flag fazem parte do conjunto de
// caracteres válidos

// Criar uma lista para inserir as strings que serão
// impressas (linhas de texto e linhas de flags inválidadas)
// Ex: echo -nex "test" -> "-nex test"

}
