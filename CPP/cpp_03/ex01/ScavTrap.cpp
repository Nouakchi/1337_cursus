#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Default ScavTrap constructor called\n";
}

ScavTrap::ScavTrap( ScavTrap &copy ) : ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor called for " + copy.name + "\n";
}

ScavTrap &ScavTrap::operator=( ScavTrap &copy )
{
    this->name = copy.name;
    this->HP = copy.HP;
    this->EP = copy.EP;
    this->AD = copy.AD;
    return (*this);
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
    std::cout << "ScavTrap params constructor \n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " + this->name + " is now in Gate keeper mode\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap deconstructor called\n";
}

unsigned int ScavTrap::getHp()
{
    return (this->HP);
}

unsigned int ScavTrap::getEp()
{
    return (this->EP);
}

unsigned int ScavTrap::getAd()
{
    return (this->AD);
}

std::string ScavTrap::getName()
{
    return (this->name);
}