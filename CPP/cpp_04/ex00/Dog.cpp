
#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog Deafault constructor\n";
}

Dog::Dog( std::string type ) : Animal(type)
{
    std::cout << "Params constructor for " + type + "\n";
}

Dog::Dog( const Dog &copy ) : Animal(copy)
{
    std::cout << "copy constructor for " + type + "\n";
}

Dog::~Dog()
{
    std::cout << "Destructor fro " + type + "\n";
}

Dog &Dog::operator = (const Dog &copy )
{
    this->type = copy.type;
    std::cout << "copy assignement for " + type + "\n";
}

void Dog::makeSound()
{
    std::cout << "Dogs d'ont meow\n";
}