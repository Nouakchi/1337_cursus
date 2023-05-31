#include <iostream>
#include "Zombie.hpp"

int main()
{
    Zombie *zombie;

    zombie = NULL;
    zombie = zombie->newZombie( "foo" );
    zombie->randomChump("boo");
    delete zombie;
    return (0);
}