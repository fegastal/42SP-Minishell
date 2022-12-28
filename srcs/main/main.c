/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:52:51 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/19 12:59:08 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"
#include "minishell.h"

// void func(void *content, int is_first, int is_last);
static void	print_node(void *content, int is_first, int is_last)
{
	t_ev_node	*node;

	node = content;
	if (is_first)
		printf("[");
	printf("(%s=%s)", node->name, node->value);
	if (is_last)
		printf("]");
	else
		printf(", ");
}

int	main(/*int argc, char *argv[]*/)
{
	core_init();
	clear_screen();

	printf("[ENVIRONMENT VARIABLES]\n\t");
	ft_lst_func_apply(&(g_core.ev_list), print_node);
	printf("\n");

	set_ev("Test42", "424242", 0);
	set_ev("TEST3", "333", 0);

	printf("[ENVIRONMENT VARIABLES]\n\t");
	ft_lst_func_apply(&(g_core.ev_list), print_node);
	printf("\n");

	handle_signal();
	core_loop();
	rl_clear_history();
	return (0);
}
