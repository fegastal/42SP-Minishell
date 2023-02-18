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
char	*ft_xstr_join(char const *sep, char const *str1, char const *str2);
char	*ft_xstr_append(char const *str1, char const *str2);
int		ft_xstr_match_set(char *str, char *set);

#endif
