#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
	brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}
