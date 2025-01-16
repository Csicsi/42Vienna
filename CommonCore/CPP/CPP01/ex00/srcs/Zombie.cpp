#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

void Zombie::announce(void) {
	std::cout <<  this->name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie(void) {
	std::cout << this->name << " has died again\n";
}
