MAIN	=	minishell.c\
			handlers.c\
			shell_loop.c\
			get_environment.c get_environment_utils.c\
			prepare_functions.c\
			generate_heredoc.c\
			heredoc.c\
			garbage_collect.c

PSRCS	=	lexer.c tokens.c parsing.c cmds.c ft_getcmd.c utils.c ft_str_to_env.c ft_expand_sign.c ft_check_sign.c ft_check_env.c

SRCS	=	echo.c\
			cd.c cd_utils.c\
			pwd.c\
			env.c\
			exit.c\
			export.c export_utils.c export_utils2.c\
			unset.c\
			builtins.c builtins_utils.c\
			close_pipes.c\
			execute_cmds.c\
			execute_single.c\
			ft_dup2.c\
			get_command.c\
			get_env_arr.c\
			processing_streams.c\
			init_seer.c\
			init_paths.c init_paths_utils.c\
			check_longlong.c\
			wildcard.c wildcard_utils.c

SRCS_P	=	$(addprefix $(EXECUTION_P), $(SRCS))

PSRCS_P =	$(addprefix $(PDIR), $(PSRCS))

OBJS	=	$(SRCS:.c=.o) $(MAIN:.c=.o)

POBJS	=	$(PSRCS:.c=.o)

LIBFT_P	=	../libft/

LIBFT	= ../libft/libft.a

OBJS_P	=	$(addprefix $(BIN), $(OBJS))

POBJS_P	=	$(addprefix $(BIN), $(POBJS))

HEADER	=	minishell.h

HEADER_P	=	$(addprefix $(INCLUDES), $(HEADER)) parsing/parsing.h\
				execution/execution.h

EXECUTION_P	=	execution/

PDIR	=	./parsing/

BIN		= ../bin/

INCLUDES	= ../includes/

NAME	= ../minishell

CFLAGS	=	-Wall -Wextra -Werror

LDFLAGS = -L/goinfre/$(USER)/.brew/opt/readline/lib

READL	= -lreadline

CPPFLAGS = -I/goinfre/$(USER)/.brew/opt/readline/include

all:	$(NAME)

$(NAME):	$(OBJS_P) $(POBJS_P) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS_P) $(POBJS_P) $(READL) $(LIBFT) -o $@

../bin/%.o:	%.c $(HEADER_P)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

../bin/%.o:	execution/%.c $(HEADER_P)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

../bin/%.o:	parsing/%.c $(HEADER_P)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_P)

clean:
	$(RM) $(OBJS_P)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
