#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
private:
	// No private members;
public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);

	class UnknownFormException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	Form *makeForm(std::string formName, std::string target);
	Form *makePresidentialPardonForm(std::string target);
	Form *makeRobotomyRequestForm(std::string target);
	Form *makeShrubberyCreationForm(std::string target);
};

#endif
