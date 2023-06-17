
# ifndef __CAT_H__
# define __CAT_H__

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat( std::string type );
    Cat( const Cat &copy );
    ~Cat();

    Cat &operator = (const Cat &copy );

    void makeSound();
};


# endif