#include "Form.hpp"

Form::Form() {
	std::cout << "Form default constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &other) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = other;
}

Form &Form::operator=(const Form &other) {
	std::cout << "Form assignation operator called"
		<< std::endl;
	if (this != &other) {
		name = other.name;
	}
	return *this;
}
