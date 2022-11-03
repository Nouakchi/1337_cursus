# -*- Makefile -*-

CC = CC
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf_utils.c \
		ft_printf.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a

all: ${NAME} 

${NAME}: ${OBJS} 
	ar -rcs ${NAME} ${OBJS}

%.o:%.c
	${CC} ${CFLAGS} -c $<

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re