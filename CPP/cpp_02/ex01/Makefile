CPP				= c++
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
NAME			= run
OBJS			= main.o Fixed.o
INCLUDES		= Fixed.hpp

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CPP) $(CPPFLAGS) -o $@ $(OBJS)

%.o:	%.cpp $(INCLUDES)
		$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all