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

// Função com erro!!!
void echo(t_cmd *cmd)
{
	char	**iter;
	t_echo	e;
	char	*temp;

	e.find_flag = 1;
	e.ignore_newline = 0;
	//e.final_str = ft_strdup("");
	e.final_str = NULL;
	iter = cmd->args + 1;
	while (*iter != NULL)
	{
		if (e.find_flag && (*iter)[0] == '-')
		{
			printf("entrou\n");
			if (ft_xstr_match_set((*iter + 1), "n"))
				e.ignore_newline = 1;
			else
			{
				e.find_flag = 0;
				temp = ft_xstr_join(" ", 2, e.final_str, *iter);
				free(e.final_str);
				e.final_str = temp;
			}
		}
		else
		{
			e.find_flag = 0;
			temp = ft_xstr_join(" ", 2, e.final_str, *iter);
			free(e.final_str);
			e.final_str = temp;
		}
		iter++;
	}
	printf("ECHO: %s\n", e.final_str);
	if (!e.ignore_newline)
		printf("\n");
	free(e.final_str);
}
