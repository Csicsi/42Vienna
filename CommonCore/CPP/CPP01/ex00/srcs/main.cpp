#include "../includes/Zombie.hpp"
#include <iostream>

int main(void) {
	//Heap Zombie
	std::cout << "***Heap Zombie***\n";
	Zombie *heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	delete heapZombie;

	//Stack Zombie
	std::cout << "***Stack Zombie***\n";
	randomChump("stackZombie");

	//Multiple Heap Zombies
	std::cout << "***Multiple Heap Zombies***\n";
	Zombie *heapZombie1 = newZombie("heapZombie1");
	Zombie *heapZombie2 = newZombie("heapZombie2");
	heapZombie1->announce();
	heapZombie2->announce();
	delete heapZombie1;
	delete heapZombie2;

	//Multiple Stack Zombies
	std::cout << "***Multiple Stack Zombies***\n";
	randomChump("stackZombie1");
	randomChump("stackZombie2");

	//Mixed
	std::cout << "***Mixed***\n";
	Zombie *heapZombie3 = newZombie("heapZombie3");
	randomChump("stackZombie3");
	heapZombie3->announce();
	delete heapZombie3;

	//empty
	std::cout << "***Empty***\n";
	Zombie *emptyZombie = newZombie("");
	emptyZombie->announce();
	delete emptyZombie;
	randomChump("");

	return 0;
}
