#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int main()
{
	// subject
	std::cout << "Subject tests:" << std::endl;
	{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}

	// additional tests
	std::cout << "Additional tests:" << std::endl;
	{
		Weapon rubberChicken = Weapon("rubber chicken");
		Weapon baguette = Weapon("baguette");
		Weapon spoonOfDoom = Weapon("spoon of doom");
		Weapon oversizedPillow = Weapon("oversized pillow");
		Weapon nerfGun = Weapon("nerf gun loaded with foam rockets");
		Weapon dadJokeBook = Weapon("dad joke book");
		Weapon ancientFloppyDisk = Weapon("ancient floppy disk with 1.44MB of pure rage");

		HumanA alice("Alice", rubberChicken);
		HumanB bob("Bob");

		alice.attack();
		bob.attack();

		bob.setWeapon(baguette);
		bob.attack();

		rubberChicken.setType("golden rubber chicken with +3 charisma");
		alice.attack();
		bob.setWeapon(spoonOfDoom);
		bob.attack();

		Weapon unusedWeapon = Weapon("mystical toothpick of destiny");
		bob.setWeapon(oversizedPillow);
		bob.attack();

		alice.attack();

		bob.setWeapon(nerfGun);
		bob.attack();

		dadJokeBook.setType("dad joke book filled with puns");
		bob.setWeapon(dadJokeBook);
		bob.attack();

		bob.unsetWeapon();
		bob.attack();

		bob.setWeapon(ancientFloppyDisk);
		bob.attack();

		//HumanA eve("Eve", NULL);
	}
	return 0;
}
