CPP                     = c++
CPPFLAGS                = -Wall -Wextra -Werror -std=c++98
NAME                    = run
OBJS                    = main.o Utils.o Base.o
INCLUDES                = Base.hpp A.hpp B.hpp C.hpp Utils.hpp

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