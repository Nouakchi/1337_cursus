RM			=	rm -rf
OBJS_DIR	=	bin/
LIBFT		=	libft.a
MANDATORY	=	manda
BONUS		=	bonus
NAME		=	push_swap

all:
	@make -C libft
	@make -C $(MANDATORY)

bonus:
	@make -C libft
	@make -C $(BONUS)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(LIBFT) $(NAME)

re: fclean all

.PHONY: bonus