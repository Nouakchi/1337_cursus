all:
	@mkdir -p bin
	@make -C libft/
	@make -C mandatory/

bonus:
	@mkdir -p bbin
	@make -C libft/
	@make -C bonus/

clean:
	@make clean -C mandatory/
	@make clean -C bonus/
	@make clean -C libft/

fclean:
	@make fclean -C mandatory/
	@make clean -C bonus/
	@make fclean -C libft/

re: fclean all

.PHONY:	all clean fclean re bonus
