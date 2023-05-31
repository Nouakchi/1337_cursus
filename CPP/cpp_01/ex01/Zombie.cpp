#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << this->name + "\n";
}

void Zombie::announce( void )
{
    std::cout << this->name + ":  BraiiiiiiinnnzzzZ...\n";
}

Zombie* Zombie::zombieHorde( int N, std::string name )
{
    Zombie  *zombies;
    try
    {
        zombies = new Zombie[N];
        for (int i=0;i < N; i++)
            zombies[i].name = name;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (zombies);
}