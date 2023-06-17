
#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat Deafault constructor\n";
}

Cat::Cat( const Cat &copy ) : Animal(copy)
{
    std::cout << "copy constructor for " + type + "\n";
}

Cat::~Cat()
{
    std::cout << "Destructor fro " + type + "\n";
}

Cat &Cat::operator = (const Cat &copy )
{
    this->type = copy.type;
    std::cout << "copy assignement for " + type + "\n";
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "cats d'ont bark\n";
}