##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

NAME	=	libmy

SRC	=	my_putchar.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_put_nbr.c	\
		str_to_word_array.c	\
		my_getnbr.c	\
		my_strdup.c	\
		my_strcmp.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -I./../include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
