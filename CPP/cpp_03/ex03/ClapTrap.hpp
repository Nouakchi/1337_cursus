
# ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

#include <iostream>

class ClapTrap
{
protected:
    std::string name;
    unsigned int HP;
    unsigned int EP;
    unsigned int AD;

public:
    ClapTrap();
    ClapTrap( ClapTrap &copy );
    ClapTrap( unsigned int HP , unsigned int EP , unsigned int AD , std::string name);
    ClapTrap &operator = ( ClapTrap &copy );
    ~ClapTrap();

    ClapTrap( std::string name );

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

# endif