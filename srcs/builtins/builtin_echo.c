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

#include "builtins.h"

static void	add_to_final_str(t_echo *e, char *str);
static void	print_final_str(t_echo *e);

int	builtin_echo(t_cmd *cmd)
{
	char	**iter;
	t_echo	e;

	e.find_flag = 1;
	e.ignore_newline = 0;
	e.final_str = NULL;
	iter = cmd->args + 1;
	while (*iter != NULL)
	{
		if (e.find_flag && (*iter)[0] == '-')
		{
			if (ft_xstr_match_set((*iter + 1), "n"))
				e.ignore_newline = 1;
			else
				add_to_final_str(&e, *iter);
		}
		else
			add_to_final_str(&e, *iter);
		iter++;
	}
	print_final_str(&e);
	return (0);
}

static void	add_to_final_str(t_echo *e, char *str)
{
	char	*trimmed_str;
	char	*temp;

	e->find_flag = 0;
	trimmed_str = ft_strtrim(str, "\"");
	temp = ft_xstr_join(" ", e->final_str, trimmed_str);
	free(e->final_str);
	free(trimmed_str);
	e->final_str = temp;
}

static void	print_final_str(t_echo *e)
{
	if (e->final_str != NULL)
		printf("%s", e->final_str);
	if (!e->ignore_newline)
		printf("\n");
	free(e->final_str);
}

// void echo(t_cmd *cmd)
// {
// 	char	**iter;
// 	t_echo	e;
// 	char	*temp;

// 	e.find_flag = 1;
// 	e.ignore_newline = 0;
// 	e.final_str = ft_strdup("");
// 	iter = cmd->args + 1;
// 	while (*iter != NULL)
// 	{
// 		if (e.find_flag && (*iter)[0] == '-')
// 		{
// 			if (ft_xstr_match_set((*iter + 1), "n"))
// 				e.ignore_newline = 1;
// 			else
// 			{
// 				e.find_flag = 0;
// 				temp = ft_xstr_join(" ", e.final_str, *iter);
// 				free(e.final_str);
// 				e.final_str = temp;
// 			}
// 		}
// 		else
// 		{
// 			e.find_flag = 0;
// 			temp = ft_xstr_join(" ", e.final_str, *iter);
// 			free(e.final_str);
// 			e.final_str = temp;
// 		}
// 		iter++;
// 	}
// 	printf("%s", e.final_str);
// 	if (!e.ignore_newline)
// 		printf("\n");
// 	free(e.final_str);
// }
