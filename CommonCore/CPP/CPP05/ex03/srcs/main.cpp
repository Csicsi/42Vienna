#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat Alice("Alice", 1);

	Intern intern;

	try {
		std::cout << "Presidential Pardon Form:" << std::endl;
		Form *form = intern.makeForm("presidential pardon", "target1");
		std::cout << *form << std::endl;
		Alice.signForm(*form);
		Alice.executeForm(*form);
		delete form;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nRobotomy Request Form:" << std::endl;
		Form *form2 = intern.makeForm("robotomy request", "target2");
		std::cout << *form2 << std::endl;
		Alice.signForm(*form2);
		Alice.executeForm(*form2);
		delete form2;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nShrubbery Creation Form:" << std::endl;
		Form *form3 = intern.makeForm("shrubbery creation", "target3");
		std::cout << *form3 << std::endl;
		Alice.signForm(*form3);
		Alice.executeForm(*form3);
		delete form3;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nUnknown Form:" << std::endl;
		Form *form3 = intern.makeForm("unknown", "target3");
		if (form3 == NULL) {
			std::cout << "Form not created" << std::endl;
			return 1;
		}
		std::cout << *form3 << std::endl;
		Alice.signForm(*form3);
		Alice.executeForm(*form3);
		delete form3;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	return 0;
}
