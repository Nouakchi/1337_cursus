#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("unknow") , HP(100) , EP(50) , AD(20) 
{
    std::cout << "Default constructor called for unknown ClapTrap\n";
}

ClapTrap::ClapTrap( ClapTrap &copy )
{
    *this = copy;
    std::cout << "Copy constructor called for " + this->name + " ClapTrap\n";
}

ClapTrap &ClapTrap::operator = ( ClapTrap &copy )
{
    std::cout << "Copy assignement op called for " + this->name + " ClapTrap\n";
    this->name = copy.name;
    this->HP = copy.HP;
    this->EP = copy.EP;
    this->AD = copy.AD;
    return (*this);
}

ClapTrap::ClapTrap( std::string _name ) : name(_name) , HP(100) , EP(50) , AD(20)
{
    std::cout << "Param constructor called for " + this->name + " ClapTrap\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "Deconstructor called for " + this->name + " ClapTrap\n";
}

void ClapTrap::attack( const std::string& target )
{
    if (this->EP > 0 && this->HP > 0)
    {
        std:: cout << "ClapTrap " + this->name + " attacks " + target \
        + ", causing " << this->AD << " points of damage!\n";
        this->EP--;
    }
    else
        std::cout << "0 EP or HP for ClapTrap " + this->name + "\n";
}

void ClapTrap::takeDamage( unsigned int amount )
{
    if (this->HP >= amount)
    {
        this->HP -= amount;
        std::cout << "ClapTrap " + this->name + " takes " << amount << " points of damage\n";
    }
    else
    {
        this->HP = 0;
        std::cout << "ClapTrap " + this->name + " is now off\n";
    }
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if (this->EP > 0)
    {
        this->HP += amount;
        this->EP--;
        std::cout << "ClapTrap " + this->name + " get repaired !!\n";
    }
    else
        std::cout << "ClapTrap " + this->name + " no energy left\n";
}