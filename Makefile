# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 12:47:21 by lsilva-q          #+#    #+#              #
#    Updated: 2023/03/13 19:37:24 by fgastal-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

CC				= cc
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
				  main/main_loop.c											\
				  main/signals.c											\
				  main/terminal_utils.c										\
				  main/cmd_stack/exec_line.c								\
				  main/cmd_stack/exec_cmd.c									\
				  main/cmd_stack/get_tmp_file.c								\
				  main/cmd_stack/clear_section.c							\
				  main/cmd_stack/get_line_context.c							\
				  main/cmd_stack/open_section_files.c						\
				  main/cmd_stack/close_section_files.c						\
				  main/debug/print_section.c								\
				  main/debug/print_section_slice.c							\
				  main/debug/print_section_context.c						\
				  main/debug/print_g_core.c									\
				  main/debug/print_line_context.c							\
				  main/debug/print_slice.c									\
				  core/core_init.c											\
				  core/core_clear.c											\
				  core/clear_ev.c											\
				  core/get_ev.c												\
				  core/set_ev.c												\
				  core/rmv_ev.c												\
				  core/utils/ev_name_is_valid.c								\
				  core/utils/split_ev_line.c								\
				  core/utils/update_clear_paths.c							\
				  core/utils/update_clear_envp.c							\
				  core/utils/get_str_no_quotes.c							\
				  core/errors/file_permission_error.c						\
				  core/errors/home_not_set_error.c							\
				  core/errors/no_such_file_or_dir_error.c					\
				  core/errors/not_a_valid_identifier_error.c				\
				  core/errors/syntax_error.c								\
				  core/errors/wrong_builtin_args_error.c					\
				  core/errors/numeric_arg_required_error.c					\
				  cmd/new_cmd.c												\
				  cmd/clear_cmd.c											\
				  cmd/get_cmd_path.c										\
				  cmd/print_cmd.c											\
				  cmd/is_builtin.c											\
				  xstring/ft_xstr_join.c									\
				  xstring/ft_xstr_mjoin.c									\
				  xstring/ft_xstr_match_set.c								\
				  xstring/ft_xstr_append.c									\
				  xstring/ft_xstr_supplant.c								\
				  xstring/ft_xstr_replace.c									\
				  xstring/ft_xstr_rmv_set.c									\
				  parser/expand_line.c										\
				  parser/pipe_split_line.c									\
				  parser/redir_split_line.c									\
				  parser/parse_context.c									\
				  parser/new_redir_slice.c									\
				  parser/expand_file_path.c									\
				  parser/utils/is_valid_ev_char_on_splitter.c				\
				  parser/utils/print_slice_list.c							\
				  builtins/call_builtin.c									\
				  builtins/builtin_echo.c 									\
				  builtins/builtin_pwd.c									\
				  builtins/builtin_unset.c									\
				  builtins/builtin_exit.c									\
				  builtins/builtin_export.c									\
				  builtins/builtin_env.c									\
				  builtins/builtin_cd.c										\
				  error/error.c

SUBDIRS			= main		main/cmd_stack		main/debug					\
				  core		core/errors			core/utils					\
				  parser	parser/utils									\
				  builtins													\
				  error														\
				  xstring													\
				  cmd														\
				  ev_utils
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

valgrind:		$(NAME)
				valgrind --leak-check=full --show-leak-kinds=all \
				--suppressions=readline.supp ./$(NAME)

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
