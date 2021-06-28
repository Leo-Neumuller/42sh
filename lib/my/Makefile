##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	add_char_to_array.c\
		add_str_to_array.c\
		add_to_double_arr.c\
		int_to_binary.c\
		long_to_hex.c\
		my_getnbr.c\
		my_int_to_str.c\
		my_printf.c\
		my_put_long.c\
		my_put_nbr.c\
		my_putchar.c\
		my_putstr.c\
		my_revstr.c\
		my_strcmp.c\
		my_strcpy.c\
		my_strlen.c\
		my_strlowcase.c\
		my_strstr.c\
		print_non_printable.c\
		put_str_in_list.c\
		read_file.c\
		sort_d_arr_alpha.c\
		uint_to_hex.c\
		my_ptrarrlen.c\
		my_atoi.c\
		str_to_word_array.c\
		check_str_alpha.c\
		my_itoa.c\
		my_strncmp.c\
		insert_in_double_arr.c\

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/
	rm $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../libmy.a

re: fclean all
