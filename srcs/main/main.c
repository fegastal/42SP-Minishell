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

// static void	print_ev_node(void *content, size_t i, int is_first, int is_last);
// static void	print_tk_node(void *content, size_t i, int is_first, int is_last);
// static void	print_tokens(t_msh_tknz *tokens);

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

	// printf("[ENVIRONMENT VARIABLES]\n\t");
	// ft_lst_func_apply(&(g_core.ev_list), print_ev_node);
	// printf("\n");

	// ------

	handle_signal();
	main_loop();
	core_clear();
	// rl_clear_history();
	exit(g_core.last_status);
}

// Debug purposes only

// static void	print_tokens(t_msh_tknz *tokens)
// {
// 	int	i;

// 	i = 0;
// 	while (i < TOKENS_COUNT)
// 	{
// 		printf("\t%s:\n\t\t[", get_token_name(i));
// 		ft_lst_func_apply(tokens->tokens + i, print_tk_node);
// 		printf("]\n\t]");
// 		if (i != TOKENS_COUNT - 1)
// 			printf(",\n");
// 		i += 1;
// 	}
// }

// static void	print_ev_node(void *content, size_t index, int is_first, int is_last)
// {
// 	t_ev_node	*node;

// 	node = content;
// 	if (is_first)
// 		printf("[");
// 	printf("(<%lu> %s=%s)", index, node->name, node->value);
// 	if (is_last)
// 		printf("]");
// 	else
// 		printf(", ");
// }

// static void	print_tk_node(void *content, size_t index, int is_first, int is_last)
// {
// 	t_msh_token	*node;

// 	node = content;
// 	// if (is_first)
// 	// 	printf("\t%s:\n\t\t[", get_token_name(node->type));
// 	printf("\n\t\t\t(<%lu> ('%c') %p)", index, *(node->ptr), node->ptr);
// 	if (is_last)
// 		printf("\n\t\t");
// 	else
// 		printf(",");
// 	is_first = is_first;
// }
