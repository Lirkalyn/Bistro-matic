##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## fghj
##

NAME	=	libmy.a

SRC		=	my_putchar.c	\
			my_putstr.c		\
			my_put_nbr.c	\
			my_revstr.c		\
			my_strlen.c		\
			my_atoi.c		\
			fill.c			\
			fill2.c			\
			parser.c		\
			result.c		\
			result2.c		\
			negnbr.c        \
			multiplicator.c	\
			divisator.c		\
			soustractor.c	\
			modulator.c 	\
			sumator.c		\
			my_strcpy.c		\
			soustractor2.c	\
			base_changer.c	\
			error.c			\
			error2.c

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
			cp ./error.h $(HPATH)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)
			rm -f ../$(NAME)

re		:	fclean $(NAME)

.PHONY	:	$(NAME) clean fclean re
