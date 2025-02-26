#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "target", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", target, 145, 137) {}

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

	std::ofstream file((getTarget() + "_shrubbery").c_str());
	if (!file) {
		std::cerr << "Error: Could not open file for writing\n";
		return;
	}

	file << "               .o00o\n"
			<< "             o000000oo\n"
			<< "            00000000000o\n"
			<< "           00000000000000\n"
			<< "        oooooo  00000000  o88o\n"
			<< "     ooOOOOOOOoo  ```''  888888\n"
			<< "   OOOOOOOOOOOO'.qQQQQq. `8888'\n"
			<< "  oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n"
			<< "  OOOOOOOOOO'.QQQQQQQQQQ/ /q\n"
			<< "   OOOOOOOOO QQQQQQQQQQ/ /QQ\n"
			<< "     OOOOOOOOO `QQQQQQ/ /QQ'\n"
			<< "       OO:F_P:O `QQQ/  /Q'\n"
			<< "          \\. \\ |  // |\n"
			<< "          d\\ \\\\|_////\n"
			<< "          qP| \\ _' `|Ob\n"
			<< "             \\  / \\  \\Op\n"
			<< "             |  | O| |\n"
			<< "     _       /\\. \\_/ /\\\n"
			<< "      `---__/|_\\   //|  __\n"
			<< "            `-'  `-'`-'-'\n";

	file.close();
}

