/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_redir_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:38:48 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 20:38:48 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	print_redir_type(int type)											// DEBUG
{																				// DEBUG
	if (type == REDIR_IN)														// DEBUG
		ft_putstr_fd("REDIR_IN", 1);											// DEBUG
	else if (type == REDIR_OUT)													// DEBUG
		ft_putstr_fd("REDIR_OUT", 1);											// DEBUG
	else if (type == REDIR_APPEND)												// DEBUG
		ft_putstr_fd("REDIR_OUT", 1);											// DEBUG
	else if (type == REDIR_HEREDOC)												// DEBUG
		ft_putstr_fd("REDIR_HEREDOC", 1);										// DEBUG
	else if (type == REDIR_NONE)												// DEBUG
		ft_putstr_fd("REDIR_NONE", 1);											// DEBUG
	else if (type == REDIR_CMD)													// DEBUG
		ft_putstr_fd("REDIR_CMD", 1);											// DEBUG
}																				// DEBUG

/*
	Dynamically allocates memory for a new element in a chained
	list of redirects (t_redir_slice), initializes its fields with
	the values passed as arguments, and returns a pointer to this
	new element.
*/
t_redir_slice	*new_redir_slice(int type, int fd, char *str)
{
	t_redir_slice	*slice;

	ft_putstr_fd("new_redir_slice (args): ", 1);								// DEBUG
	ft_putstr_fd("{ type=", 1);													// DEBUG
	print_redir_type(type);														// DEBUG
	ft_putstr_fd(", fd=", 1);													// DEBUG
	ft_putnbr_fd(fd, 1);														// DEBUG
	ft_putstr_fd(", str=\"", 1);												// DEBUG
	ft_putstr_fd(str, 1);														// DEBUG
	ft_putstr_fd("\" }\n", 1);													// DEBUG
	slice = malloc(sizeof(t_redir_slice));
	*slice = (t_redir_slice) {0};
	slice->type = type;
	slice->fd = fd;
	slice->str = str;
	ft_xstr_supplant(&slice->str, get_str_no_quotes(str));
	ft_xstr_supplant(&slice->str, ft_strtrim(slice->str, " "));
	// ft_putstr_fd("new_redir_slice (before expanding): ", 1);					// DEBUG
	// ft_putstr_fd("{ type=", 1);													// DEBUG
	// print_redir_type(type);														// DEBUG
	// ft_putstr_fd(", fd=", 1);													// DEBUG
	// ft_putnbr_fd(fd, 1);														// DEBUG
	// ft_putstr_fd(", str=\"", 1);												// DEBUG
	// ft_putstr_fd(str, 1);														// DEBUG
	// ft_putstr_fd("\" }\n", 1);													// DEBUG
	if (type != REDIR_NONE)
		ft_xstr_supplant(&slice->str, expand_file_path(slice->str));
	// ft_putstr_fd("new_redir_slice (after expanding): ", 1);						// DEBUG
	// ft_putstr_fd("{ type=", 1);													// DEBUG
	// print_redir_type(type);														// DEBUG
	// ft_putstr_fd(", fd=", 1);													// DEBUG
	// ft_putnbr_fd(fd, 1);														// DEBUG
	// ft_putstr_fd(", str=\"", 1);												// DEBUG
	// ft_putstr_fd(str, 1);														// DEBUG
	// ft_putstr_fd("\" }\n", 1);													// DEBUG
	return (slice);
}
