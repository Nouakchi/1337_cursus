CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME		= megaphone
OBJS		= megaphone.o

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)

%.o:	%.cpp
	$(CPP) $(CPPFLAGS) -c $<

clean:	
	rm -r $(OBJS)

fclean:	clean
	rm  -r $(NAME)

re:	fclean all
