##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

NAME	=	libmy.a

SRC		=	my_putchar.c	\
			my_putstr.c		\
			my_put_nbr.c	\
			my_revstr.c		\
			my_strlen.c		\
			my_atoi.c		\
			fill.c			\
			parser.c		\
			result.c		\
			negnbr.c        \
			fill2.c

HPATH	=	./../../include/

OBJ		=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
			gcc -c $(SRC)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
			cp ./$(NAME) ../
			cp ./my.h $(HPATH)
			cp ./bistromatic.h $(HPATH)
			cp ./eval_expr.h $(HPATH)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)
			rm -f ../$(NAME)
			rm -f $(HPATH)*

re		:	fclean $(NAME)

.PHONY	:	$(NAME) clean fclean re
