##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	src/my_malloc.c	\
		src/my_create.c	\

NAME	=	libmy_malloc.so

OBJ	=	$(SRC:.c=.o)

CC = gcc

INCLUDE	=	-I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -fPIC -shared -o $(NAME)  $(OBJ) $(INCLUDE) -Wno-deprecated -fPIC

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
