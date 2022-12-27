# -*- Makefile -*-

CC		= 	cc
NAME	=	../libft.a
SRCS	= 	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_atoi.c \
			ft_strdup.c \
			ft_calloc.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c	\
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstclear.c \

BIN_DIR	=	../bin/
INC_DIR	=	../includes/
CFLAGS	=	-Wall -Wextra -Werror -I
RM		=	rm -f
OBJS	=	$(addprefix ${BIN_DIR},${SRCS:.c=.o})

all: 		${NAME} ${INC_DIR}libft.h

${NAME}: 	${OBJS} 
	@ar -rcs ${NAME} ${OBJS}

${BIN_DIR}%.o: %.c 
	@mkdir -p ${BIN_DIR}
	@${CC} ${CFLAGS} ${INC_DIR} -c $< -o $@

clean: 
	${RM} $(OBJS)

fclean: 	clean
	${RM} ${NAME}

re: 		fclean all bonus

.PHONY: 	all clean fclean re