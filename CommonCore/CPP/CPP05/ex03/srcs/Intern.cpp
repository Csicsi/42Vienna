#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Form *Intern::makePresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

Form *Intern::makeRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

Form *Intern::makeShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form *Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			switch (i) {
				case 0:
					return makePresidentialPardonForm(target);
				case 1:
					return makeRobotomyRequestForm(target);
				case 2:
					return makeShrubberyCreationForm(target);
			}
		}
	}
	return NULL;
}
