# -*- Makefile -*-

CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME = client server

all: ${NAME} 

${NAME}:
	${CC} ${CFLAGS} client.c -o client
	${CC} ${CFLAGS} server.c -o server

clean:
	rm -f ${NAME}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re