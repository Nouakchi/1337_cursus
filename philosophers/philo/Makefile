# -*- Makefile -*-

CC		=	CC

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	philo

SRC		=	main.c	\

HEADER	=	philosophers.h	\

BIN		=	../bin/

INCLUDES	=	../includes/

OBJS	=	$(SRC:.c=.o)


OBJS_P	=	$(addprefix $(BIN), $(OBJS))

all:	$(NAME)

$(NAME):	$(OBJS_P)
	$(CC) $(CFLAGS) $(OBJS_P) -o $@

../bin/%.o:	%.c $(addprefix $(INCLUDES), $(HEADER))
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_P)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re