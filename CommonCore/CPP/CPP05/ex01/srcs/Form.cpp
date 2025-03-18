#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _toSign(150), _toExecute(150) {}

Form::Form(const std::string name, const int toSign, const int toExecute) :
	_name(name), _signed(false), _toSign(toSign), _toExecute(toExecute) {
	if (_toSign < 1 || _toExecute < 1) {
		throw Form::GradeTooHighException();
	} else if (_toSign > 150 || _toExecute > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::~Form() {}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed),
	_toSign(other._toSign), _toExecute(other._toExecute) {
	*this = other;
}

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

const std::string &Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _toSign) {
		throw Form::GradeTooLowException();
	}
	_signed = true;
}

int Form::getToSign() const {
	return _toSign;
}

int Form::getToExecute() const {
	return _toExecute;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "Form " << form.getName() << " is ";
	if (!form.getSigned()) {
		out << "not ";
	}
	out << "signed, requires grade " << form.getToSign()
		<< " to sign, and grade " << form.getToExecute()
		<< " to execute.";
	return out;
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}
