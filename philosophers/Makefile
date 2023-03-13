# -*- Makefile -*-

RM	=	rm -rf

all:
	@mkdir -p bin
	@make -C philo

bonus:	
	@makdir -p bin
	@make -C bonus

clean:	
	@make clean -C philo
	@$(RM) bin

fclean:	clean
	@make fclean -C philo

re: fclean all

.PHONY: all clean fclean re bonus
	