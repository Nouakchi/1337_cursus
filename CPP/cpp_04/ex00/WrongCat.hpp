
# ifndef __WRONGCAT_H__
# define __WRONGCAT_H__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat( const WrongCat &copy );
    ~WrongCat();

    WrongCat &operator = (const WrongCat &copy );

    void makeSound() const;
};


# endif