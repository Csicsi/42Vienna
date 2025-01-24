#include "../includes/ScavTrap.hpp"

int main() {
	{
		std::cout << "***Testing default constructor***" << std::endl;
		ScavTrap scavTrapDefault;
		scavTrapDefault.attack("target");
		scavTrapDefault.takeDamage(20);
		scavTrapDefault.beRepaired(10);
		scavTrapDefault.guardGate();
	}

	std::cout << "\n***Testing name constructor***" << std::endl;
	ScavTrap scavTrapName("ScavTrapName");
	scavTrapName.attack("target");
	scavTrapName.takeDamage(30);
	scavTrapName.beRepaired(20);
	scavTrapName.takeDamage(200); // ScavTrapName has died!
	scavTrapName.guardGate(); // ScavTrapName Cannot guard gate!

	std::cout << "\n***Testing copy constructor***" << std::endl;
	ScavTrap scavTrapToCopy("ScavTrapToCopy");
	ScavTrap scavTrapCopy(scavTrapToCopy);
	scavTrapCopy.attack("target");
	scavTrapCopy.takeDamage(15);
	scavTrapCopy.beRepaired(10);
	scavTrapCopy.guardGate();

	std::cout << "\n***Testing assignation operator***" << std::endl;
	ScavTrap scavTrapAssignation;
	scavTrapAssignation = scavTrapToCopy;
	scavTrapAssignation.attack("assignation_target");
	scavTrapAssignation.takeDamage(10);
	scavTrapAssignation.beRepaired(10);
	scavTrapAssignation.guardGate();

	std::cout << "\n***Testing insufficient energy points***" << std::endl;
	ScavTrap scavTrapEnergy("ScavTrapEnergy");
	scavTrapEnergy.guardGate();
	for (int i = 0; i < 50; i++) {
		scavTrapEnergy.attack("target");
	} // Deplete all energy points
	scavTrapEnergy.guardGate(); // Should fail due to no energy
	scavTrapEnergy.beRepaired(10); // Should fail due to no energy

	std::cout << "\n***Testing Overkill***" << std::endl;
	ScavTrap scavTrapOverkill("ScavTrapOverkill");
	scavTrapOverkill.takeDamage(150); // Should "kill" the ScavTrap
	scavTrapOverkill.beRepaired(10); // Should fail as it's "dead"

	std::cout << "\n***Destructor messages***" << std::endl;

	return 0;
}
