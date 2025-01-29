#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

void Cat::setIdea(const std::string &idea, int index) {
	brain->setIdea(idea, index);
}

std::string Cat::getIdea(int index) const {
	return brain->getIdea(index);
}
