# -*- Makefile -*-

CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME = client server
BNAME = client_bonus server_bonus

all: ${NAME} 

bonus: ${BNAME}

${NAME}:
	${CC} ${CFLAGS} client_bonus.c -o client
	${CC} ${CFLAGS} server_bonus.c -o server

${BNAME}:
	${CC} ${CFLAGS} client_bonus.c -o client_bonus
	${CC} ${CFLAGS} server_bonus.c -o server_bonus

clean:
	rm -f ${NAME} ${BNAME}

fclean: clean
	rm -f ${NAME} ${BNAME}

re: fclean all

.PHONY: all clean fclean re