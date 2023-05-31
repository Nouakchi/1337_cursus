#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
    this->name = name;
}

void HumanB::attack()
{
    std::cout << this->name + " attacks with their " + this->weapon->getType() + "\n";
}

void HumanB::setWeapon( Weapon &Weapon )
{
    this->weapon = &Weapon;
}