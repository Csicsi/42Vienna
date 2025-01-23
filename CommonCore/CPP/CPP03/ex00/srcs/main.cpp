#include "../includes/ClapTrap.hpp"

int main() {
	ClapTrap clapTrap("ClapTrap");
	ClapTrap clapTrap2(clapTrap);
	ClapTrap clapTrap3 = clapTrap;

	clapTrap.takeDamage(10);
	clapTrap.beRepaired(10);
	clapTrap.attack("target");
	clapTrap.attack("target");
	clapTrap.attack("target");
	clapTrap.attack("target");
	clapTrap.attack("target");
	clapTrap.attack("target");
	clapTrap.attack("target");
	clapTrap.attack("target");
	clapTrap.attack("target");
	clapTrap.attack("target");
	clapTrap.beRepaired(5);
	clapTrap2.attack("target");
	clapTrap3.attack("target");
	return 0;
}
