#include "../includes/DiamondTrap.hpp"

int main() {
	{
		std::cout << "***Testing default constructor***" << std::endl;
		DiamondTrap diamondTrapDefault;
		diamondTrapDefault.attack("target");
		diamondTrapDefault.takeDamage(30);
		diamondTrapDefault.beRepaired(20);
		diamondTrapDefault.whoAmI();
		diamondTrapDefault.guardGate();
		diamondTrapDefault.highFivesGuys();
	}

	std::cout << "\n***Testing name constructor***" << std::endl;
	DiamondTrap diamondTrapName("DiamondTrapName");
	diamondTrapName.attack("name_target");
	diamondTrapName.takeDamage(50);
	diamondTrapName.beRepaired(30);
	diamondTrapName.whoAmI();
	diamondTrapName.guardGate();
	diamondTrapName.highFivesGuys();
	diamondTrapName.takeDamage(200); // DiamondTrapName has died!
	diamondTrapName.whoAmI(); // DiamondTrapName cannot high five!

	std::cout << "\n***Testing copy constructor***" << std::endl;
	DiamondTrap diamondTrapToCopy;
	DiamondTrap diamondTrapCopy(diamondTrapToCopy);
	diamondTrapCopy.attack("target");
	diamondTrapCopy.takeDamage(40);
	diamondTrapCopy.beRepaired(25);
	diamondTrapCopy.whoAmI();
	diamondTrapCopy.guardGate();
	diamondTrapCopy.highFivesGuys();

	std::cout << "\n***Testing assignation operator***" << std::endl;
	DiamondTrap diamondTrapAssignation;
	diamondTrapAssignation = diamondTrapToCopy;
	diamondTrapAssignation.attack("target");
	diamondTrapAssignation.takeDamage(30);
	diamondTrapAssignation.beRepaired(15);
	diamondTrapAssignation.whoAmI();
	diamondTrapAssignation.guardGate();
	diamondTrapAssignation.highFivesGuys();

	std::cout << "\n***Testing insufficient energy points***" << std::endl;
	DiamondTrap diamondTrapEnergy("DiamondTrapEnergy");
	diamondTrapEnergy.whoAmI();
	diamondTrapEnergy.guardGate();
	diamondTrapEnergy.highFivesGuys();
	for (int i = 0; i < 98; i++) {
		diamondTrapEnergy.attack("target");
	} // Deplete all energy points
	diamondTrapEnergy.guardGate(); // Should fail due to no energy
	diamondTrapEnergy.highFivesGuys(); // Should fail due to no energy
	diamondTrapEnergy.attack("target"); // Should fail due to no energy
	diamondTrapEnergy.beRepaired(10); // Should fail due to no energy

	std::cout << "\n***Testing Overkill***" << std::endl;
	DiamondTrap diamondTrapOverkill("DiamondTrapOverkill");
	diamondTrapOverkill.takeDamage(150); // Should "kill" the DiamondTrap
	diamondTrapOverkill.whoAmI(); // Should fail as it's "dead"
	diamondTrapOverkill.guardGate(); // Should fail as it's "dead"
	diamondTrapOverkill.highFivesGuys(); // Should fail as it's "dead"
	diamondTrapOverkill.attack("target"); // Should fail as it's "dead"

	std::cout << "\n***Destructor messages***" << std::endl;

	return 0;
}

