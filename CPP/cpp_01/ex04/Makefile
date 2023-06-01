CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME		= run
OBJS		= main.o Utils.o
INCLUDES	= Utils.h

all:	$(NAME)
	touch file

$(NAME):	$(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)

%.o:	%.cpp $(INCLUDES)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:	
	rm -rf $(OBJS) file

fclean:	clean
	rm -rf $(NAME)

re:	fclean all