#include "../includes/Zombie.hpp"

Zombie::Zombie(void) : name("") {
	std::cout << " A zombie has risen from its grave\n";
}

void Zombie::announce(void) {
	std::cout <<  this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(const std::string &name) {
	this->name = name;
}

Zombie::~Zombie(void) {
	std::cout << this->name << " has died again\n";
}
