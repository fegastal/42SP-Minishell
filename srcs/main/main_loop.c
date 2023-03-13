/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:24:40 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 16:21:53 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Responsible for prompting the user for input, displaying a
	prompt message, and doing some input manipulation before
	returning it to the caller.
*/
char	*create_prompt(void)
{
	char	*input;
	char	*last_endl;

	input = readline(get_prefix());
	if (input == NULL)
		write(1, "\n", 1);
	else if (input[0] != '\0')
		add_history(input);
	else if (input != NULL)
	{
		last_endl = ft_strrchr(input, '\n');
		if (*last_endl)
			*last_endl = '\0';
	}
	return (input);
}

void	main_loop(void)
{
	char	*input;
	char	*expanded_input;

	while (g_core.is_running)
	{
		input = create_prompt();
		if (input)
		{
			if (input[0] != '\0')
			{
				expanded_input = expand_line(input);
				exec_line(expanded_input);
				free(expanded_input);
			}
			free(input);
		}
		else
			break ;
	}
}
