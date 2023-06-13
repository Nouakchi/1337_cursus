#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap( FragTrap &copy );
    FragTrap &operator = ( FragTrap &copy );
    ~FragTrap();

    FragTrap( std::string name );

    void highFivesGuys();

    unsigned int getHp();
    unsigned int getEp();
    unsigned int getAd();
    
    std::string getName();
};


