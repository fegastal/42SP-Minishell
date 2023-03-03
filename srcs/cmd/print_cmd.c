/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:26:05 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/09 12:26:05 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	print_cmd(t_cmd *cmd)
{
	char	**tmp;

	printf("{\n  path: %s,\n  args: [", cmd->path);
	tmp = cmd->args;
	while (*tmp != NULL)
	{
		printf("\n    %s", *tmp);
		if (*(tmp + 1) != NULL)
			printf(",");
		else
			printf("\n  ");
		tmp++;
	}
	printf("]\nargs_count: %d\n}\n", cmd->args_count);
}
