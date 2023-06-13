#include "ScavTrap.hpp"

int	main()
{
	ScavTrap a;
	ScavTrap b("houssine");
	ScavTrap c(b);
	ScavTrap d("othman");

	a = d;

	std::cout << "Hp: " << a.getHp() << " Ep: " << a.getEp() << " Ad: " << a.getAd() << " Name: " << a.getName() << std::endl;
	std::cout << "Hp: " << b.getHp() << " Ep: " << b.getEp() << " Ad: " << b.getAd() << " Name: " << b.getName() << std::endl;
	std::cout << "Hp: " << c.getHp() << " Ep: " << c.getEp() << " Ad: " << c.getAd() << " Name: " << c.getName() << std::endl;
	std::cout << "Hp: " << d.getHp() << " Ep: " << d.getEp() << " Ad: " << d.getAd() << " Name: " << d.getName() << std::endl;
	return 0;
}