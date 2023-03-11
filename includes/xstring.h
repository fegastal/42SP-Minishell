/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:04 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/01/03 14:43:04 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XSTRING_H
# define XSTRING_H

# include <stdarg.h>
# include "libft_x.h"
# include "ft_list.h"

char	*ft_xstr_mjoin(const char *sep, unsigned int count, ...);
char	*ft_xstr_join(const char *sep, const char *str1, const char *str2);
char	*ft_xstr_append(const char *str1, const char *str2);
int		ft_xstr_match_set(const char *str, const char *set);
void	ft_xstr_supplant(char **str, char *new);
char	*ft_xstr_replace(const char *str, const char *old, const char *new);

#endif
