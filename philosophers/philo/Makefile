# -*- Makefile -*-

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	philo

SRC		=	main.c			\
			philo_routine.c	\
			utils.c			\
			state.c			\
			philosophers.c

HEADER	=	philosophers.h	\

BIN		=	../bin/

INCLUDES	=	../includes/

OBJS	=	$(SRC:.c=.o)


OBJS_P	=	$(addprefix $(BIN), $(OBJS))

all:	$(NAME)

$(NAME):	$(OBJS_P)
	$(CC) $(CFLAGS) $(OBJS_P) -g -o $@

../bin/%.o:	%.c $(addprefix $(INCLUDES), $(HEADER))
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_P)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re