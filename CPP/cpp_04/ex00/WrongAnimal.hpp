# ifndef __WRONGANIMAL_H__
# define __WRONGANIMAL_H__

#include <iostream>

class WrongAnimal
{
protected:
   std::string type;

public:
    WrongAnimal();
    WrongAnimal( const WrongAnimal  &copy );
    WrongAnimal( std::string type );
    ~WrongAnimal();

    WrongAnimal &operator = ( const WrongAnimal &copy );

    std::string getType() const;

    void makeSound() const;
};



# endif