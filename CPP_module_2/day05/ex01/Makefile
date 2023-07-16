CPP                     = c++
CPPFLAGS                = -Wall -Wextra -Werror -std=c++98
NAME                    = run
OBJS                    = main.o Bureaucrat.o  Form.o
INCLUDES                = Bureaucrat.hpp Form.hpp

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