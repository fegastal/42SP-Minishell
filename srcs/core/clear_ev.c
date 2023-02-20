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

void	clear_ev(void *ptr)
{
	t_ev	*ev;

	ev = (t_ev *) ptr;
	free((void *) ev->name);
	free((void *) ev->value);
	free(ev);
}
