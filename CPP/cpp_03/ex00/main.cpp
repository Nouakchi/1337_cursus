#include "ClapTrap.hpp"

int main()
{
    ClapTrap othman("othman");
	ClapTrap houssine("houssine");
	ClapTrap jalloul;
	jalloul = houssine;

	othman.attack("houssine");
	houssine.takeDamage(0);
	houssine.takeDamage(132);
	houssine.attack("Me");
	houssine.beRepaired(2);
	houssine.takeDamage(10);
	jalloul.attack("othman");
    return (0);
}