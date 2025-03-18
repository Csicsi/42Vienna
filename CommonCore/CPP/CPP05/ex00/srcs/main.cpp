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
		std::cout << "\n" << alice << std::endl;

		alice.decrementGrade(1);
		std::cout << "After decrement: " << alice << std::endl;

		std::cout << "Expexted: too low" << std::endl;
		alice.decrementGrade(5);
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nExpexted: too high" << std::endl;
		Bureaucrat john("John", 0);
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nExpexted: too low" << std::endl;
		Bureaucrat jane("Jane", 151);
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
