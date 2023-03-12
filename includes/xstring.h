/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:04 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 19:56:38 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -----------------
// |  Definitions  |
// -----------------

#ifndef XSTRING_H
# define XSTRING_H

// ------------
// | Includes |
// ------------

# include <stdarg.h>
# include "libft_x.h"
# include "ft_list.h"

// ----------------------------------
// | Prototype of helper functions  |
// | to handle strings              |
// ----------------------------------

char	*ft_xstr_mjoin(const char *sep, unsigned int count, ...);
char	*ft_xstr_join(const char *sep, const char *str1, const char *str2);
char	*ft_xstr_append(const char *str1, const char *str2);
int		ft_xstr_match_set(const char *str, const char *set);
void	ft_xstr_supplant(char **str, char *new);
char	*ft_xstr_replace(const char *str, const char *old, const char *new);

#endif
