#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}
