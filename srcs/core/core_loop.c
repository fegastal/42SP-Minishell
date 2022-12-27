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

char *create_prompt(void)
{
	char *input;

	input = readline(get_prefix());
	if (input == NULL)
	{
		write(2, "\n", 1);
		free(input);
		exit(1);
	}
	add_history(input);
	return (input);
}

void core_loop(void)
{
	char *input;

	(void)input;

	while(1)
	{
		//readline(get_prefix());
		input = create_prompt();
		if (input)
			free(input);
	}
}
