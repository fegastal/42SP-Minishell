/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:24:40 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/12/13 15:24:40 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_prompt(void)
{
	char *input;

	input = readline(get_prefix());
	if (input == NULL)
		write(2, "\n", 1);
	else if (input[0] != '\0')
		add_history(input);
	return (input);
}

void	main_loop(void)
{
	char	*input;
	char	*expanded_input;
	// t_cmd	*cmd;

	(void) input;

	while(g_core.is_running)
	{
		input = create_prompt();
		if (input)
		{
			if (input[0] == '\0')
				continue;
			expanded_input = expand_line(input);
			exec_line(expanded_input);
			// cmd = new_cmd(expanded_input);
			free(expanded_input);
			// exec_cmd(cmd);
			// print_cmd(cmd);
			free(input);
			// clear_cmd(cmd);
		}
		else
		{
			// dup2(g_core.std_out, STDOUT_FILENO);
			// printf("Last status: %d\n", g_core.last_status);
			break;
		}
	}
}
