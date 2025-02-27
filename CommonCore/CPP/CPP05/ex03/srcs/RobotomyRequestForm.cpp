#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "target", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == false) {
		std::cerr << "Form not signed" << std::endl;
		return;
	}
	if (executor.getGrade() > this->getToExecute())
		throw GradeTooLowException();
	std::srand(time(0));
	system("aplay ~/electric-drill-03.wav >/dev/null 2>&1");
	std::cout << "***drill noises***" << std::endl;
	if (rand() % 2 == 1)
		std::cout << this->getTarget()
			<< " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed!" << std::endl;
}
