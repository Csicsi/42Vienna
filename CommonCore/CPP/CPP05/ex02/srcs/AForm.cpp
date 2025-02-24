#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _toSign(150), _toExecute(150) {}

AForm::AForm(const std::string name, const int toSign, const int toExecute) :
	_name(name), _signed(false), _toSign(toSign), _toExecute(toExecute) {
	if (_toSign < 1 || _toExecute < 1) {
		throw AForm::GradeTooHighException();
	} else if (_toSign > 150 || _toExecute > 150) {
		throw AForm::GradeTooLowException();
	}
}

AForm::~AForm() {}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed),
	_toSign(other._toSign), _toExecute(other._toExecute) {
	*this = other;
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (_signed) {
		std::cout << "AForm " << _name << " is already signed, no need for "
			<< bureaucrat.getName() << " to sign." << std::endl;
		return;
	}
	if (bureaucrat.getGrade() > _toSign) {
		throw AForm::GradeTooLowException();
	}
	_signed = true;
	std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
}

int AForm::getToSign() const {
	return _toSign;
}

int AForm::getToExecute() const {
	return _toExecute;
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm) {
	out << "AForm " << AForm.getName() << " is ";
	if (!AForm.getSigned()) {
		out << "not ";
	}
	out << "signed, requires grade " << AForm.getToSign()
		<< " to sign, and grade " << AForm.getToExecute()
		<< " to execute.";
	return out;
}
