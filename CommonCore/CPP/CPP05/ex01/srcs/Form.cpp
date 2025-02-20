#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _toSign(150),
	_toExecute(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int toSign, const int toExecute) :
	_name(name), _signed(false), _toSign(toSign), _toExecute(toExecute) {
	std::cout << "Form constructor called" << std::endl;
	if (_toSign < 1 || _toExecute < 1) {
		throw Form::GradeTooHighException();
	} else if (_toSign > 150 || _toExecute > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed),
	_toSign(other._toSign), _toExecute(other._toExecute) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = other;
}

Form &Form::operator=(const Form &other) {
	std::cout << "Form assignation operator called"
		<< std::endl;
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}
