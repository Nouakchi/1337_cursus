
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat Deafault constructor\n";
}

WrongCat::WrongCat( const WrongCat &copy ) : WrongAnimal(copy)
{
    std::cout << "copy constructor for " + type + "\n";
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor fro " + type + "\n";
}

WrongCat &WrongCat::operator = (const WrongCat &copy )
{
    this->type = copy.type;
    std::cout << "copy assignement for " + type + "\n";
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCats d'ont bark\n";
}