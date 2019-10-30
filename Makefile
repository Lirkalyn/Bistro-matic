##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for the main of bistromatic
##

NAME	=	calc

SRC		=	main.c

HPATH   =	./include/

HEADERS =   ./lib/my/my.h		\
			./lib/my/bistromatic.h

OBJ		=	$(SRC:.c=.o)

all		:	headers $(NAME)

$(NAME)	:	$(OBJ)
			make -C ./lib/my
			gcc $(OBJ) -o $(NAME) -L./lib/my -lmy -Wall -Wextra

headers	:
			cp $(HEADERS) $(HPATH)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean $(NAME)

val		:	valgrind ./$(NAME) 0123456789 "()+-*/%"

.PHONY	:	all $(NAME) headers clean fclean re val