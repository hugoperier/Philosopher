##
## EPITECH PROJECT, 2018
## philosofer
## File description:
## 
##

CC	=	gcc

RM	=	rm -f

SRCS	=	src/main.c		\
		src/philosopher.c

OBJS	=	$(SRCS:.c=.o)

LIB	=	-L. -lriceferee -pthread

NAME	=	philo

CFLAGS	+=	-W -Wall -Wextra -pedantic -I inc

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
