/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_getindex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:19:32 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/10/23 18:28:06 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Description: Return the index of a node in a list.
//
// Arguments: 'lst' is a pointer to a list. 'node' is a pointer to a node.
//
// Return value: -1 if 'lst' or 'node' value is NULL, or if node does'nt belong
//				to 'lst'. If success, return the index of the node.
int	ft_lst_getindex(t_ftlist *lst, t_ftnode *node)
{
	t_ftnode	*tmp_inc;
	t_ftnode	*tmp_dec;
	int			index_inc;
	int			index_dec;

	index_inc = 0;
	index_dec = lst->size - 1;
	tmp_inc = lst->front;
	tmp_dec = lst->back;
	while (tmp_inc != tmp_dec)
	{
		if (tmp_inc == node)
			return (index_inc);
		else if (tmp_dec == node)
			return (index_dec);
		index_inc += 1;
		index_dec -= 1;
		tmp_inc = tmp_inc->next;
		tmp_dec = tmp_dec->prev;
	}
	if (tmp_inc != NULL && tmp_inc == node)
		return (index_inc);
	return (-1);
}
