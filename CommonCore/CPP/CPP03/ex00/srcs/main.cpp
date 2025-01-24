#include "../includes/ClapTrap.hpp"

int main() {
	std::cout << "***Testing default constructor***" << std::endl;
	ClapTrap clapTrapDefault;
	clapTrapDefault.attack("target");
	clapTrapDefault.takeDamage(5);
	clapTrapDefault.beRepaired(5);

	std::cout << "\n***Testing name constructor***" << std::endl;
	ClapTrap clapTrapName("ClapTrapName");
	clapTrapName.attack("target");
	clapTrapName.takeDamage(5);
	clapTrapName.beRepaired(5);
	clapTrapName.takeDamage(15); // ClapTrapName has died!
	clapTrapName.attack("target"); // ClapTrapName Cannot attack!
	clapTrapName.beRepaired(5); // ClapTrapName Cannot be repaired!

	std::cout << "\n***Testing copy constructor***" << std::endl;
	ClapTrap clapTrapToCopy("ClapTrapToCopy");
	ClapTrap clapTrapCopy(clapTrapToCopy);
	clapTrapCopy.attack("target");
	clapTrapCopy.takeDamage(5);
	clapTrapCopy.beRepaired(5);

	std::cout << "\n***Testing assignation operator***" << std::endl;
	ClapTrap clapTrapAssignation;
	clapTrapAssignation = clapTrapToCopy;
	clapTrapAssignation.attack("target");
	clapTrapAssignation.takeDamage(5);
	clapTrapAssignation.beRepaired(5);

	std::cout << "\n***Testing insufficient energy points***" << std::endl;
	ClapTrap clapTrapEnergy("ClapTrapEnergy");
	clapTrapEnergy.beRepaired(5);
	for (int i = 0; i < 9; i++) {
		clapTrapEnergy.attack("target");
	} // Deplete all energy points
	clapTrapEnergy.attack("target"); // Should fail due to no energy
	clapTrapEnergy.beRepaired(5); // Should fail due to no energy

	std::cout << "\n***Testing Overkill***" << std::endl;
	ClapTrap clapTrapOverkill("ClapTrapOverkill");
	clapTrapOverkill.takeDamage(15); // Should "kill" the ClapTrap
	clapTrapOverkill.beRepaired(5); // Should fail as it's "dead"

	std::cout << "\n***Destructor messages***" << std::endl;

	return 0;
}
