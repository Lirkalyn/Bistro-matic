##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

NAME 	=	libmy.a

SRC	=	my_putchar.c	\
		my_putstr.c	\
		my_put_nbr.c	\
		my_revstr.c	\
		my_strlen.c

HEADERS	=	my.h		\
		bistromatic.h

HPATH	=	./../../include/

OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
		gcc -c $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
		cp ./$(NAME) ../
		cp ./$(HEADERS) $(HPATH)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f ../$(NAME)
		rm -f $(HPATH)$(HEADERS)

re:		fclean $(NAME)

.PHONY:		$(NAME) clean fclean re
