#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(100, 100, 30, "unknow")
{
    std::cout << "Default FragTrap constructor called\n";
}

FragTrap::FragTrap( FragTrap &copy ) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called for " + copy.name + "\n";
}

FragTrap &FragTrap::operator=( FragTrap &copy )
{
    this->name = copy.name;
    this->HP = copy.HP;
    this->EP = copy.EP;
    this->AD = copy.AD;
    return (*this);
}

FragTrap::FragTrap( std::string name ) : ClapTrap(100, 100, 30, name)
{
    std::cout << "FragTrap params constructor \n";
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " + this->name + " request a positive high fives \n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap deconstructor called\n";
}

unsigned int FragTrap::getHp()
{
    return (this->HP);
}

unsigned int FragTrap::getEp()
{
    return (this->EP);
}

unsigned int FragTrap::getAd()
{
    return (this->AD);
}

std::string FragTrap::getName()
{
    return (this->name);
}