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

/*
	The clear_ev function is responsible for freeing the memory
	allocated to an environment variable (t_ev), deallocating
	the memory allocated to the variable name and value,
	as well as the t_ev structure itself.
*/
void	clear_ev(void *ptr)
{
	t_ev	*ev;

	ev = (t_ev *) ptr;
	free((char *) ev->name);
	free((char *) ev->value);
	free(ev);
}
