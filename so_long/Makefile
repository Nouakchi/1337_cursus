# -*- Makefile -*-

NAME := play
BNAME := play_bonus
CC := cc
CFLAGS := -Wall -Wextra -Werror
PTH := ./Mandatory
BPTH := ./bonus
SRCS := so_long.c \
 		read_map.c \
		ft_split.c \
		get_next_line.c \
		get_next_line_utils.c \
		check_map.c \
		paint.c \
		play_init.c \
		game_over.c \
		start_play.c \
		update_ply.c \
		valid_path.c
BSRCS := so_long_bonus.c \
 		read_map_bonus.c \
		ft_split_bonus.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		check_map_bonus.c \
		paint_bonus.c \
		play_init_bonus.c \
		game_over_bonus.c \
		start_play_bonus.c \
		update_ply_bonus.c \
		display_moves.c \
		ft_itoa.c \
		ft_strdup.c \
		ft_strlcpy.c \
		sprite.c 
SRCS_FILES := $(addprefix $(PTH)/, $(SRCS))
BSRCS_FILES := $(addprefix $(BPTH)/, $(BSRCS))
OSRCS := ${SRCS_FILES:.c=.o}
OBSRCS := ${BSRCS_FILES:.c=.o}
IncLibx := -L.. -lmlx -lXext -lX11
all:	${NAME}

${NAME}: ${OSRCS}
	${CC} ${CFLAGS} ${OSRCS} ${IncLibx} -g -o ${NAME}
bonus:	${OBSRCS}
	${CC} ${CFLAGS} ${OBSRCS} ${IncLibx} -o ${BNAME}
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
clean: 
	rm -f ${OSRCS} ${OBSRCS}
fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re bonus
