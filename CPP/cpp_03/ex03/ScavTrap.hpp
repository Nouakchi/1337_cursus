
# ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
public:
    ScavTrap();
    ScavTrap( ScavTrap &copy );
    ScavTrap &operator = ( ScavTrap &copy );
    ~ScavTrap();

    ScavTrap( std::string name );

    void guardGate();

    unsigned int getHp();
    unsigned int getEp();
    unsigned int getAd();
    
    std::string getName();
};

# endif