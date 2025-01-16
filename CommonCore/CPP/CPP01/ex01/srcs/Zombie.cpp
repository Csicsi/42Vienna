#include "../includes/Zombie.hpp"

Zombie::Zombie(void) : name("") {}

Zombie::Zombie(std::string name) : name(name) {}

void Zombie::announce(void) {
	std::cout <<  this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(const std::string &name) {
	this->name = name;
}

Zombie::~Zombie(void) {
	std::cout << this->name << " has died again\n";
}
