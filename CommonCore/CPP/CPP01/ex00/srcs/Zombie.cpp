#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
	std::cout << this->name << " has risen from its grave\n";
}

void Zombie::announce(void) {
	std::cout <<  this->name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie(void) {
	std::cout << this->name << " has died again\n";
}
