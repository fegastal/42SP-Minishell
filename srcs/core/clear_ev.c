/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_ev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:05:00 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/07 21:05:00 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	clear_ev(void *ev)
{
	char	*name;
	char	*value;

	name = (char *) (((t_ev *) ev))->name;
	value = (char *) (((t_ev *) ev))->value;
	free(name);
	free(value);
	free(ev);
}
