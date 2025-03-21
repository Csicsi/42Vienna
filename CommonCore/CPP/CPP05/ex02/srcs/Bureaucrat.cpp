#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade) : _name(_name) {
	if (_grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (_grade > LOWEST_GRADE)
		throw GradeTooLowException();
	this->_grade = _grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	(void)other;
	return *this;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade(int num) {
	if (_grade - num < HIGHEST_GRADE)
		throw GradeTooHighException();
	_grade -= num;
}

void Bureaucrat::decrementGrade(int num) {
	if (_grade + num > LOWEST_GRADE)
		throw GradeTooLowException();
	_grade += num;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", grade: " << bureaucrat.getGrade();
	return out;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &form) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}
