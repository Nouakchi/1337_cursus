# -*- Makefile -*-

NAME := so_long
CC := cc
CFLAGS := -Wall -Wextra -Werror
PTH := ./Mandatory
SRCS := so_long.c \
 		read_map.c \
		ft_split.c \
		get_next_line.c \
		get_next_line_utils.c \
		check_map.c \
		paint_bonus.c \
		play_init.c \
		game_over.c \
		start_play.c \
		update_ply.c \
		display_moves_bonus.c \
		ft_itoa.c \
		ft_strdup.c \
		ft_strlcpy.c \
		sprite_bonus.c \
		valid_path.c \
		ft_printf_utils.c \
		ft_printf.c

SRCS_FILES := $(addprefix $(PTH)/, $(SRCS))
OSRCS := ${SRCS_FILES:.c=.o}
IncLibx := -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit

all:	${NAME}

${NAME}: ${OSRCS} ${PTH}/so_long.h ${PTH}/libft.h ${PTH}/ft_printf.h
	${CC} ${CFLAGS} -I /usr/local/includes ${SRCS_FILES} ${IncLibx} -o ${NAME}

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean: 
	rm -f ${OSRCS} ${OBSRCS}

fclean: clean
	rm -f ${NAME} ${BNAME}

re: fclean all

.PHONY: all clean fclean re bonus
