CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME		= logs
OBJS		= Account.o tests.o
INCLUDES	= Account.hpp

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)

%.o:	%.cpp $(INCLUDES)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:	
	rm $(OBJS)

fclean:	clean
	rm $(NAME)

re:	fclean all