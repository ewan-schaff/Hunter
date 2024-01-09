##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## write a makefile to compils my_ls
##

SRC =	lib/my/my_str_to_word_array.c	\
		lib/my/my_putchar.c			\
		lib/my/my_put_nbr.c			\
		lib/my/my_putstr.c			\
		lib/my/my_strlen.c			\
		lib/my/my_put_octal.c		\
		lib/my/my_put_hexa_low.c	\
		lib/my/my_put_hexa_up.c		\
		lib/my/my_put_revstr.c		\
		lib/my/my_put_nbr_long.c	\
		lib/my/my_put_revstr.c		\
		lib/my/my_printf.c			\
		lib/my/my_put_float.c		\
		lib/my/my_put_sci.c 		\
		lib/my/my_put_sci_up.c		\
		lib/my/my_put_hexa_base.c	\
		lib/my/space_flag.c 		\
		lib/my/my_strcpy.c			\
		lib/my/my_strcmp.c			\
		lib/my/my_ls_a.c			\
		lib/my/my_ls_base.c			\
		lib/my/my_ls_d.c			\
		lib/my/my_ls_l.c			\
		lib/my/my_ls_la.c			\
		lib/my/directory.c			\
		lib/my/directory_a.c		\
		lib/my/check_directory_d.c 	\
		lib/my/my_strcmp.c			\
		lib/my/check_dash.c			\
		lib/my/error_managment.c	\
		lib/my/my_ls_l_base.c		\
		lib/my/my_getnbr.c			\
		lib/my/my_str_isnum.c		\
		lib/my/my_strcat.c			\
		./src/display_pictures.c	\
		./src/display_pictures2.c	\
		./src/game_clock.c			\
		./src/my_hunter2.c

UNIT = --coverage -lcriterion

OBJ	=	$(SRC:.c=.o)

FLAG = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

NAME =	my_hunter

$(NAME):	$(OBJ)
	ar rc libmy.a $(OBJ)
	gcc -g -o $(NAME) main.c -L. -lmy $(FLAG)

clean:
	rm  -f $(OBJ)

fclean:		clean
	rm -f $(NAME)
	rm -f libmy.a
	rm -f *.gcno
	rm -f *.gcda
	rm -f *~

re: 	fclean $(NAME)
