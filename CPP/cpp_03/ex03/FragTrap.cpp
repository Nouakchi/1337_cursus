#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(100, 100, 30, "unknow")
{
    std::cout << "Default FragTrap constructor called\n";
}

FragTrap::FragTrap( FragTrap &copy ) : ClapTrap(copy.HP,copy.EP,copy.AD,copy.name)
{
    std::cout << "FragTrap copy constructor called for " + copy.name + "\n";
}

FragTrap &FragTrap::operator=( FragTrap &copy )
{
    if (&copy != this)
    {
        std::cout << "FragTrap copy assignement op called for " + this->name + "\n";
        this->name = copy.name;
        this->HP = copy.HP;
        this->EP = copy.EP;
        this->AD = copy.AD;
    }
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
    return (100);
}

unsigned int FragTrap::getEp()
{
    return (100);
}

unsigned int FragTrap::getAd()
{
    return (30);
}

std::string FragTrap::getName()
{
    return (this->name);
}