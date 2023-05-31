CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME		= phonebook
OBJS		= PhoneBook.o Contact.o main.o utils.o
INCLUDES	= Contact.hpp PhoneBook.hpp utils.h

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