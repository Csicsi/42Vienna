#include "../includes/Zombie.hpp"
#include <iostream>

int main(void) {

	//Horde of 5 zombies
	std::cout << "***Horde of 5 zombies***\n";
	Zombie *horde = zombieHorde(5, "Zombie");
	if (horde) {
		for (int i = 0; i < 5; i++) {
			horde[i].announce();
		}
		delete[] horde;
	}

	//Horde of 0 zombies
	Zombie *horde2 = zombieHorde(0, "Zombie");
	if (!horde2) {
		std::cout << "***Horde of 0 zombies***\n";
	}

	//Horde of -1 zombies
	Zombie *horde3 = zombieHorde(-1, "Zombie");
	if (!horde3) {
		std::cout << "***Horde of -1 zombies***\n";
	}

	return 0;
}
