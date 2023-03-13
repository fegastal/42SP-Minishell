/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:52:51 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 16:23:56 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"
#include "minishell.h"

/*
	Starts the shell and performs various actions, such as
	initializing the shell's data structures, clearing the
	terminal screen, setting up signal handling, starting
	the main shell loop, and clearing the shell's data structures
	before exiting.
*/
int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 1)
	{
		printf("Minishell cannot have any arguments.\n");
		printf("Ending program!\n");
		return (1);
	}
	core_init(argc, argv, envp);
	clear_screen();
	handle_signal();
	main_loop();
	core_clear();
	// rl_clear_history();
	exit(g_core.last_status);
}
