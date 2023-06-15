
# ifndef __DIAMONDTRAP_H__
# define __DIAMONDTRAP_H__

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
private:
    std::string name;
public:
    DiamondTrap();
    DiamondTrap( std::string name );
    DiamondTrap( DiamondTrap &copy );
    DiamondTrap &operator = ( DiamondTrap &copy );
    ~DiamondTrap();

    void whoAmI();
    void attack(const std::string& target);
};

# endif