SRCS	= ft_isalpha.c ft_memcpy.c ft_strlcat.c ft_strtrim.c ft_isascii.c ft_memmove.c ft_strlcpy.c ft_substr.c ft_atoi.c ft_isdigit.c ft_memset.c ft_strlen.c ft_tolower.c ft_bzero.c ft_isprint.c ft_strchr.c ft_strncmp.c ft_strcmp.c ft_toupper.c ft_calloc.c ft_memchr.c ft_strdup.c ft_strnstr.c ft_isalnum.c ft_memcmp.c ft_strjoin.c ft_strrchr.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c get_next_line.c get_next_line_utils.c ft_perror.c

BONUS	= ft_lstnew.c\
		  	ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c

HEADER	= libft.h

OBJS	= ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS:.c=.o}

AR		= ar -cr

CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

all: $(NAME)

$(NAME) :	$(OBJS)
			$(AR) $(NAME) $(OBJS)

%.o : %.c $(HEADER)
		$(CC) $(CFLAGS) -c $<

bonus	: $(BONUS_OBJS)
		$(AR) $(NAME) $(BONUS_OBJS)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
