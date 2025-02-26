#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;

		bob.incrementGrade(1);
		std::cout << "After increment: " << bob << std::endl;

		std::cout << "Expexted: too high" << std::endl;
		bob.incrementGrade(5);
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat alice("Alice", 149);
		std::cout << alice << std::endl;

		alice.decrementGrade(1);
		std::cout << "After decrement: " << alice << std::endl;

		std::cout << "Expexted: too low" << std::endl;
		alice.decrementGrade(5);
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat john("John", 0);
		std::cout << "Expexted: too high" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat jane("Jane", 151);
		std::cout << "Expexted: too low" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
