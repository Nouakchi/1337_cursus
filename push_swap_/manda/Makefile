# -*- Makefile -*-

SRCS	=	push_swap.c \
			parsing.c	\
			swap.c		\
			push.c		\
			reverse.c	\
			rotate.c	\
			utils.c		\
			main.c

NAME	=	../push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I
INC_DIR	=	../includes
LIBFT	=	../libft.a

all:
	@$(CC) $(CFLAGS) $(INC_DIR) $(SRCS) $(LIBFT) -o $(NAME) -g
	@echo Mandatory is compiled.

