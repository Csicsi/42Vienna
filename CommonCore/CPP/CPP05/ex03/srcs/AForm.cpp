#include "AForm.hpp"

AForm::AForm() : _name("default"), _target("target"), _signed(false), _toSign(LOWEST_GRADE), _toExecute(LOWEST_GRADE) {}

AForm::AForm(const std::string name, const std::string target, const int toSign, const int toExecute) :
	_name(name), _target(target), _signed(false), _toSign(toSign), _toExecute(toExecute) {
	if (_toSign < HIGHEST_GRADE || _toExecute < HIGHEST_GRADE) {
		throw AForm::GradeTooHighException();
	} else if (_toSign > LOWEST_GRADE || _toExecute > LOWEST_GRADE) {
		throw AForm::GradeTooLowException();
	}
}

AForm::~AForm() {}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed),
	_toSign(other._toSign), _toExecute(other._toExecute) {
	*this = other;
}

AForm &AForm::operator=(const AForm &other) {
	(void)other;
	return *this;
}

const std::string &AForm::getName() const {
	return _name;
}

const std::string &AForm::getTarget() const {
	return _target;
}

bool AForm::getSigned() const {
	return _signed;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _toSign) {
		throw AForm::GradeTooLowException();
	}
	_signed = true;
}

int AForm::getToSign() const {
	return _toSign;
}

int AForm::getToExecute() const {
	return _toExecute;
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm) {
	out << "AForm " << AForm.getName()
	<< " has target: " << AForm.getTarget() << ", is ";
	if (!AForm.getSigned()) {
		out << "not ";
	}
	out << "signed, requires grade " << AForm.getToSign()
		<< " to sign, and grade " << AForm.getToExecute()
		<< " to execute.";
	return out;
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::NotSignedException::what() const throw() {
	return "Form is not signed";
}
