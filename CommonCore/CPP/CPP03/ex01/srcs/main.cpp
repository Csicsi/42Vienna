#include "../includes/ScavTrap.hpp"


int main() {

	{
		ScavTrap scavTrap("ScavTrap");
		scavTrap.attack("ClapTrap");
	}

	std::cout << std::endl;

	ClapTrap clapTrap("ClapTrap");
	ScavTrap scavTrap("ScavTrap");

	scavTrap.attack("ClapTrap");
	scavTrap.guardGate();
	scavTrap.takeDamage(10);
	scavTrap.beRepaired(5);

	return 0;
}
