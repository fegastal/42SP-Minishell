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
# include <readline/readline.h>

int	main(/*int argc, char *argv[]*/)
{
	clear_screen();
	core_loop();
	return (0);
}
