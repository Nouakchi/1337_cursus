#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << this->name + "\n";
}

void Zombie::announce( void )
{
    std::cout << this->name + ":  BraiiiiiiinnnzzzZ...\n";
}