##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

NAME	=	lem_in

SRC	=	src/main.c	\
		src/read_and_verif/read.c	\
		src/read_and_verif/verif.c	\
		src/read_and_verif/verif_two.c	\
		src/prepare_lem/set_settings.c	\
		src/prepare_lem/room.c	\
		src/prepare_lem/room_chain.c	\
		src/parse_and_lem/parse.c	\
		src/parse_and_lem/search_path.c	\
		src/parse_and_lem/chain_path.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -I./include -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/ re
	gcc -o $(NAME) $(OBJ) lib/libmy

clean:
	rm -f $(OBJ)

fclean: clean
	make -C lib/ fclean
	rm -f $(NAME)

re: fclean all
