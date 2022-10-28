# -*- Makefile -*-

CC = CC
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf_utils.c \
		ft_printf.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a

all: ${NAME} 

${NAME}: ${OBJS} ft_printf.h
	ar -rcs ${NAME} ${OBJS}
*.o:*.c ft_printf.h
	${CC} ${CFLAGS} -c $<

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re