CPP                     = c++
CPPFLAGS                = -Wall -Wextra -Werror -std=c++98
NAME                    = run
OBJS                    = main.o Animal.o Cat.o Dog.o WrongAnimal.o WrongCat.o
INCLUDES                = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

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