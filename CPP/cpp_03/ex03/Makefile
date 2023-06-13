CPP				= c++
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
NAME			= run
OBJS			= main.o ClapTrap.o ScavTrap.o FragTrap.o DiamondTrap.o
INCLUDES		= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

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