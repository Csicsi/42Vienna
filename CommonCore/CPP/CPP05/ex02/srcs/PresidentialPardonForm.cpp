#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "target", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	(void)other;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getToExecute())
		throw GradeTooLowException();

	std::cout << this->getTarget() << " has  been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}
