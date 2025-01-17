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

		alice.attack(); // Alice attacks with their rubber chicken
		bob.attack();   // Bob has no weapon to attack with

		bob.setWeapon(baguette);
		bob.attack(); // Bob attacks with their baguette

		rubberChicken.setType("golden rubber chicken with +3 charisma");
		alice.attack(); // Alice attacks with their golden rubber chicken with +3 charisma

		bob.setWeapon(spoonOfDoom);
		bob.attack(); // Bob attacks with their spoon of doom

		Weapon unusedWeapon = Weapon("mystical toothpick of destiny");
		bob.setWeapon(oversizedPillow);
		bob.attack(); // Bob attacks with their oversized pillow

		alice.attack(); // Alice attacks with their golden rubber chicken with +3 charisma

		bob.setWeapon(nerfGun);
		bob.attack(); // Bob attacks with their nerf gun loaded with foam rockets

		dadJokeBook.setType("dad joke book filled with puns");
		bob.setWeapon(dadJokeBook);
		bob.attack(); // Bob attacks with their dad joke book filled with puns

		bob.setWeapon(ancientFloppyDisk);
		bob.attack(); // Bob attacks with their ancient floppy disk with 1.44MB of pure rage

		//HumanA eve("Eve", NULL);
	}
	return 0;
}
