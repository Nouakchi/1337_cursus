#include "Zombie.hpp"

void check()
{
    system("leaks run");
}

int main()
{
    atexit(check);
    Zombie *zombies;

    zombies = NULL;
    zombies = zombies->zombieHorde(10, "foo");
    for(int i = 0; i < 4; i++)
        zombies[i].announce();
    delete [] zombies;
    return (0);
}