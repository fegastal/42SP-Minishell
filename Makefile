# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 12:47:21 by lsilva-q          #+#    #+#              #
#    Updated: 2022/04/19 12:58:08 by lsilva-q         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g

INCLUDES_DIR	= includes
SRCS_DIR		= srcs
OBJS_DIR		= objs
LIBS_DIR		= libs

LFTX_DIR		= $(LIBS_DIR)/libft_x
LFTX			= $(LFTX_DIR)/libft_x.a
LFTX_FLAGS		=

FTLST_DIR		= $(LIBS_DIR)/ft_list
FTLST			= $(FTLST_DIR)/ft_list.a
FTLST_FLAGS		=

SRC_FILES		= main/main.c												\
				  core/core_loop.c											\
				  core/terminal_utils.c										\
				  core/signals.c											\
				  parser/tokenize.c											\
				  parser/tokenize_utils.c

SUBDIRS			= main core parser
SRCS			= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS			= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:%.c=%.o))

HEADER_FILES	=
HEADERS			= $(addprefix $(INCLUDES_DIR)/, $(HEADER_FILES))

I_CC			= -I $(INCLUDES_DIR) -I $(LFTX_DIR) -I $(FTLST_DIR)

$(OBJS_DIR)/%.o	: $(SRCS_DIR)/%.c $(HEADERS)
				mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/, $(SUBDIRS))
				$(CC) $(CFLAGS) $(I_CC) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS) $(LFTX) $(FTLST)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lreadline $(LFTX) $(FTLST)

$(LFTX):
				make -C $(LFTX_DIR) $(LFTX_FLAGS)

$(FTLST):
				make -C $(FTLST_DIR) $(FTLST_FLAGS)

clean:
				make clean -C $(LFTX_DIR)
				$(RM) $(OBJS)
				$(RM) -r $(OBJS_DIR)

fclean:			clean
				make fclean -C $(LFTX_DIR)
				make fclean -C $(FTLST_DIR)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
