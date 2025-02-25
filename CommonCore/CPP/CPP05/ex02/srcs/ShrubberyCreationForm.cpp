#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm(target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getToExecute())
		throw GradeTooLowException();

	std::ofstream file((getName() + "_shrubbery").c_str());
	if (!file) {
		std::cerr << "Error: Could not open file for writing\n";
		return;
	}

	file << "      *      \n"
		<< "     ***     \n"
		<< "    *****    \n"
		<< "   *******   \n"
		<< "  *********  \n"
		<< " *********** \n"
		<< "     |||     \n";

	file.close();
}
