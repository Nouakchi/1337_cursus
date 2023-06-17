
# ifndef __DOG_H__
# define __DOG_H__

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog( const Dog &copy );
    ~Dog();

    Dog &operator = (const Dog &copy );

    void makeSound() const;
};


# endif