#include <iostream>
#include "../includes/Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	Bureaucrat highRank("Alice", 1);
	Bureaucrat midRank("Bob", 50);
	Bureaucrat lowRank("Charlie", 150);

	Form form("Form", 100, 50);
	std::cout << form << std::endl;

	try {
		std::cout << "\nShould work:" << std::endl;
		highRank.signForm(form);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nShould fail, low rank:" << std::endl;
		lowRank.signForm(form);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nShould fail, grade too high:" << std::endl;
		Form form2("Invalid", 10, 0);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nShould fail, grade too low:" << std::endl;
		Form form2("Invalid", 151, 100);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
