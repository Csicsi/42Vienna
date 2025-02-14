#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;

		bob.incrementGrade(1);
		std::cout << "After increment: " << bob << std::endl;

		// This should throw an exception
		bob.incrementGrade(5);
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat alice("Alice", 149);
		std::cout << alice << std::endl;

		alice.decrementGrade(1);
		std::cout << "After decrement: " << alice << std::endl;

		// This should throw an exception
		alice.decrementGrade(5);
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		// This should throw an exception (too high)
		Bureaucrat john("John", 0);
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		// This should throw an exception (too low)
		Bureaucrat jane("Jane", 151);
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
