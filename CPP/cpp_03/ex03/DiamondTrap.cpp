#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap() , ScavTrap() , FragTrap()
{
    this->name = "unknown";
    this->ClapTrap::name = this->name + "_clap_name";
    this->HP = this->FragTrap::getHp();
    this->EP = this->ScavTrap::getEp();
    this->AD = this->FragTrap::getAd();
    std::cout << "DiamondTrap " + this->name + " default constructor called\n";
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name) , ScavTrap(name) , FragTrap(name)
{
    this->name = name;
    this->ClapTrap::name = this->name + "_clap_name";
    this->HP = this->FragTrap::getHp();
    this->EP = this->ScavTrap::getEp();
    this->AD = this->FragTrap::getAd();
    std::cout << "DiamondTrap " + this->name + " params constructor called\n";
}

DiamondTrap::DiamondTrap( DiamondTrap &copy ) : ClapTrap(copy) , ScavTrap(copy) , FragTrap(copy)
{
    *this = copy;
    std::cout << "DiamondTrap " + this->name + " copy constructor called\n";
}

DiamondTrap &DiamondTrap::operator=( DiamondTrap &copy )
{
    this->name = copy.name;
    this->ClapTrap::name = this->name + "_clap_name";
    this->HP = this->FragTrap::getHp();
    this->EP = this->ScavTrap::getEp();
    this->AD = this->FragTrap::getAd();
    std::cout << "DiamondTrap " + this->name + " copy assignement op called\n";
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " + this->name + " deconstructor called\n";
}

void DiamondTrap::attack( const std::string &target )
{
    this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name is " + this->name + " and ClapTrap name is " 
    + this->ClapTrap::name + "\n";
}