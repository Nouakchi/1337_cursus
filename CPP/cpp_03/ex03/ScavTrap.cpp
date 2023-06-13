#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(100,50,20,"unknown")
{
    std::cout << "Default ScavTrap constructor called\n";
}

ScavTrap::ScavTrap( ScavTrap &copy ) : ClapTrap(copy.HP,copy.EP,copy.AD,copy.name)
{
    std::cout << "ScavTrap copy constructor called for " + copy.name + "\n";
}

ScavTrap &ScavTrap::operator=( ScavTrap &copy )
{
    if (&copy != this)
    {
        std::cout << "ScavTrap copy assignement op called for " + copy.name + "\n";
        this->name = copy.name;
        this->HP = copy.HP;
        this->EP = copy.EP;
        this->AD = copy.AD;
    }
    return (*this);
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(100,50,20,name)
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
    return (100);
}

unsigned int ScavTrap::getEp()
{
    return (50);
}

unsigned int ScavTrap::getAd()
{
    return (20);
}

std::string ScavTrap::getName()
{
    return (this->name);
}