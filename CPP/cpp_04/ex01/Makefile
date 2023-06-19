CPP                     = c++
CPPFLAGS                = -Wall -Wextra -Werror -std=c++98
NAME                    = run
OBJS                    = main.o Animal.o Cat.o Dog.o Brain.o
INCLUDES                = Animal.hpp Cat.hpp Dog.hpp Brain.hpp

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