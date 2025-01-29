#include ".hpp"

::() {
	std::cout << " default constructor called" << std::endl;
}

::~() {
	std::cout << " destructor called" << std::endl;
}

::(const  &other) {
	std::cout << " copy constructor called" << std::endl;
	*this = other;
}

 &::operator=(const  &other) {
	std::cout << " assignation operator called"
		<< std::endl;
	if (this != &other) {
		Cure = other.Cure;
	}
	return *this;
}
