##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	src/builtins/cd/cd.c						\
		src/utils/change_pwd.c						\
		src/builtins/env/env.c						\
		src/exec/handle_cmd.c						\
		src/main.c									\
		src/mysh.c									\
		src/exec/run_bin.c							\
		src/builtins/env/setenv.c					\
		src/parser/split_buffer.c					\
		src/builtins/env/unsetenv.c					\
		src/builtins/cd/cd_handle_pwd.c				\
		src/builtins/cd/cd_handle_char_path.c		\
		src/utils/handle_path_bin.c					\
		src/parser/handle_quote.c					\
		src/utils/set_pwd_if_null.c					\
		src/builtins/handle_exit.c					\
		src/splitter/handle_pipe_red_sc.c			\
		src/utils/print_error.c						\
		src/splitter/run_single_cmd.c				\
		src/builtins/check_if_builtins.c			\
		src/splitter/handle_split.c					\
		src/exec/exec_pipe.c						\
		src/splitter/handle_semicolons.c			\
		src/splitter/handle_pipes.c					\
		src/splitter/handle_redirection.c			\
		src/splitter/handle_right_redirection.c		\
		src/splitter/globbing/stars.c				\
		src/splitter/handle_or_and.c				\
		src/splitter/handle_or_and_error.c			\
		src/parser/split_buffer_redirection.c		\
		src/sh_getline/sh_getline.c					\
		src/sh_getline/key_handle.c					\
		src/sh_getline/key_struct_init.c			\
		src/sh_getline/move_cursor_handle.c			\
		src/sh_getline/move_cursor.c				\
		src/sh_getline/print_command.c				\
		src/sh_getline/tab_handle/tab_handle.c		\
		src/sh_getline/tab_handle/path_finding.c	\
		src/sh_getline/tab_handle/completion_init.c	\
		src/utils/check_str_alphanumeric.c			\
		src/utils/save_path.c						\
		src/utils/error_not_found.c					\
		src/utils/free_double_array.c				\
		src/utils/parse_home_char.c					\
		src/parser/handle_dollar.c					\
		src/utils/handle_enoexec.c					\
		src/utils/check_for_delimiter.c				\
		src/splitter/handle_left_redirection.c		\
		src/sh_getline/char_to_linked.c				\
		src/sh_getline/history/free.c				\
		src/sh_getline/history/history.c			\
		src/sh_getline/history/history_add.c		\
		src/sh_getline/history/history_down.c		\
		src/sh_getline/history/history_up.c			\
		src/sh_getline/history/load_hs_struct.c		\
		src/sh_getline/history/save_history.c		\
		src/sh_getline/history/empty_history.c		\
		src/sh_loop.c								\
		src/splitter/handle_double_l_r.c			\
		src/builtins/env/variable_env.c				\

LIB_NAME = libmy.a

CFLAGS = -I include

LIB = -L lib/ -lmy

NAME = 42sh

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	make -C lib/my
	gcc -Wall -Wextra -W -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	make -C lib/my clean
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	make -C lib/my fclean
	rm -f $(NAME)

re: fclean all

valgrind:
	gcc -o $(NAME) $(SRC) -Wall -Wextra -W $(LIB) $(CFLAGS) -g

test:
	make re
	mv 42sh tests/mysh
