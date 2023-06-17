
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "";
    std::cout << "WrongAnimal Deafault constructor\n";
}

WrongAnimal::WrongAnimal( const WrongAnimal &copy )
{
    this->type = copy.type;
    std::cout << "WrongAnimal copy Constructor\n";
}

WrongAnimal::WrongAnimal( std::string type )
{
    this->type = type;
    std::cout << "WrongAnimal Params Constructor\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Deconstructor\n";
}

WrongAnimal &WrongAnimal::operator = ( const WrongAnimal &copy )
{
    *this = copy;
    std::cout << "WrongAnimal copy assignement\n";
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "wrong animal sound\n";
}