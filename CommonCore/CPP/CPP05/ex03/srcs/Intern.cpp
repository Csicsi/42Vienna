#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Form *Intern::makePresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

Form *Intern::makeRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form *Intern::makeShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form *Intern::makeForm(std::string formName, std::string target)
{
	typedef Form *(Intern::*FormCreator)(std::string);
	FormCreator formCreators[3] = {
		&Intern::makePresidentialPardonForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makeShrubberyCreationForm};
	std::string formNames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	throw UnknownFormException();
	return NULL;
}

const char *Intern::UnknownFormException::what() const throw() {
	return "Unknown form";
}
