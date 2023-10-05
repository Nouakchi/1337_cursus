CPP                     = c++
CPPFLAGS                = -Wall -Wextra -Werror -std=c++98 
NAME                    = RPN
OBJS                    = main.o RPN.o
INCLUDES                = RPN.hpp

all:    $(NAME)

$(NAME):        $(OBJS)
				$(CPP) $(CPPFLAGS) -o $@ $(OBJS)

%.o:    %.cpp $(INCLUDES)
				$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
				rm -rf $(OBJS)

fclean: clean
				rm -rf $(NAME)

re:             fclean all