/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:24:12 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/03/12 19:55:19 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -----------------
// |  Definitions  |
// -----------------

#ifndef ERROR_H
# define ERROR_H

# define FD_ERROR 2

# define ERR_CUSTOM_ERROR -1
# define ERR_SUCCESS 0
# define ERR_FAILURE 1
# define ERR_NO_SUCH_FILE_OR_DIR 1
# define ERR_FILE_NO_PERMISSION 1
# define ERR_HOME_NOT_SET 1
# define ERR_WRONG_BUILTIN_ARGS 2
# define ERR_SYNTAX_ERROR 2
# define ERR_EXEC_NO_PERMISSION 126
# define ERR_CMD_NOT_FOUND 127

// ------------
// | Includes |
// ------------

# include <stdio.h>
# include "libft_x.h"

// -----------------------------------
// | prototype of the error function |
// -----------------------------------

int	error(int error_code, char *message);

#endif
