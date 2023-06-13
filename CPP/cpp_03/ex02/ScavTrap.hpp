#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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


