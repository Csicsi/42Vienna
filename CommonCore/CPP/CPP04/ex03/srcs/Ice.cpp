#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria("ice") {
	std::cout << "Ice copy constructor called" << std::endl;
	*this = other;
}

Ice &Ice::operator=(const Ice &other) {
	std::cout << "Ice assignation operator called"
		<< std::endl;
	(void)other;
	return *this;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice();
}
