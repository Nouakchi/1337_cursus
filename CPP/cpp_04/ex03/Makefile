CPP                     = c++
CPPFLAGS                = -Wall -Wextra -Werror -std=c++98
NAME                    = run
OBJS                    = main.o AMateria.o Character.o Ice.o Cure.o MateriaSource.o
INCLUDES                = AMateria.hpp Character.hpp Ice.hpp Cure.hpp MateriaSource.hpp ICharacter.hpp IMateriaSource.hpp

all:    $(NAME)

$(NAME):        $(OBJS)
		$(CPP) $(CPPFLAGS) -o $@ $(OBJS)

%.o:    %.cpp $(INCLUDES)
		$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re:  