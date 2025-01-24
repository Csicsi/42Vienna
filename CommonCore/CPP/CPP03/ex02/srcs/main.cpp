#include "../includes/FragTrap.hpp"

int main() {
	std::cout << "***Testing default constructor***" << std::endl;
	FragTrap fragTrapDefault;
	fragTrapDefault.attack("target");
	fragTrapDefault.takeDamage(30);
	fragTrapDefault.beRepaired(20);
	fragTrapDefault.highFivesGuys();

	std::cout << "\n***Testing name constructor***" << std::endl;
	FragTrap fragTrapName("FragTapName");
	fragTrapName.attack("name_target");
	fragTrapName.takeDamage(50);
	fragTrapName.beRepaired(30);
	fragTrapName.highFivesGuys();
	fragTrapName.takeDamage(200); // FragTrapName has died!
	fragTrapName.highFivesGuys(); // FragTrapName cannot high five!

	std::cout << "\n***Testing copy constructor***" << std::endl;
	FragTrap fragTrapToCopy;
	FragTrap fragTrapCopy(fragTrapToCopy);
	fragTrapCopy.attack("target");
	fragTrapCopy.takeDamage(40);
	fragTrapCopy.beRepaired(25);
	fragTrapCopy.highFivesGuys();

	std::cout << "\n***Testing assignation operator***" << std::endl;
	FragTrap fragTrapAssignation;
	fragTrapAssignation = fragTrapToCopy;
	fragTrapAssignation.attack("target");
	fragTrapAssignation.takeDamage(30);
	fragTrapAssignation.beRepaired(15);
	fragTrapAssignation.highFivesGuys();

	std::cout << "\n***Testing insufficient energy points***" << std::endl;
	FragTrap fragTrapEnergy("FragTrapEnergy");
	fragTrapEnergy.highFivesGuys();
	for (int i = 0; i < 100; i++) {
		fragTrapEnergy.attack("target");
	} // Deplete all energy points
	fragTrapEnergy.highFivesGuys(); // Should fail due to no energy
	fragTrapEnergy.beRepaired(10); // Should fail due to no energy

	std::cout << "\n***Testing Overkill***" << std::endl;
	FragTrap fragTrapOverkill("FragTrapOverkill");
	fragTrapOverkill.takeDamage(150); // Should "kill" the FragTrap
	fragTrapOverkill.highFivesGuys(); // Should fail as it's "dead"

	std::cout << "\n***Destructor messages***" << std::endl;

	return 0;
}
