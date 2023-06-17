
#include "Animal.hpp"

Animal::Animal()
{
    this->type = "";
    std::cout << "Animal Deafault constructor\n";
}

Animal::Animal( const Animal &copy )
{
    this->type = copy.type;
    std::cout << "Animal copy Constructor\n";
}

Animal::Animal( std::string type )
{
    this->type = type;
    std::cout << "Animal Params Constructor\n";
}

Animal::~Animal()
{
    std::cout << "Animal Deconstructor\n";
}

Animal &Animal::operator = ( const Animal &copy )
{
    *this = copy;
    std::cout << "Animal copy assignement\n";
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{

}