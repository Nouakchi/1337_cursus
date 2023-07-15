CPP                     = c++
CPPFLAGS                = -Wall -Wextra -Werror -std=c++98
NAME                    = run
OBJS                    = main.o Bureaucrat.o  AForm.o PresidentialPardonForm.o RobotomyRequestForm.o ShrubberyCreationForm.o Intern.o
INCLUDES                = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

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