CPP                     = c++
CPPFLAGS                = -Wall -Wextra -Werror -std=c++98
NAME                    = convert
OBJS                    = main.o ScalarConverter.o
INCLUDES                = ScalarConverter.hpp

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