#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 145, 137) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm(target, 145, 137) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getToExecute())
		throw GradeTooLowException();

	std::cout << this->getName() << " has  been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}
