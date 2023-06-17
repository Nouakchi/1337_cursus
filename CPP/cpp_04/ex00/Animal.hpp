# ifndef __ANIMAL_H__
# define __ANIMAL_H__

#include <iostream>

class Animal
{
protected:
   std::string type;

public:
    Animal();
    Animal( const Animal  &copy );
    Animal( std::string type );
    ~Animal();

    Animal &operator = ( const Animal &copy );

    std::string getType() const;

    virtual void makeSound() const;
};



# endif