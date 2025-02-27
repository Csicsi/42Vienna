#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat highRank("Alice", 1);
	Bureaucrat midRank("Bob", 50);
	Bureaucrat lowRank("Charlie", 150);

	try {
		std::cout << "\nShrubbery Creation Form Exception:" << std::endl;
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		std::cout << "Should fail, low rank" << std::endl;
		lowRank.signForm(shrub);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nShrubbery Creation Form Succes:" << std::endl;
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		midRank.signForm(shrub);
		std::cout << shrub << std::endl;
		midRank.executeForm(shrub);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nRobotomy Request Form Exception:" << std::endl;
		RobotomyRequestForm robot("target");
		std::cout << robot << std::endl;
		midRank.signForm(robot);
		std::cout << "Should fail, low rank" << std::endl;
		midRank.executeForm(robot);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nRobotomy Request Form Succes:" << std::endl;
		RobotomyRequestForm robot("target");
		std::cout << robot << std::endl;
		midRank.signForm(robot);
		std::cout << robot << std::endl;
		std::cout << "Should be succesfull 50% of the time" << std::endl;
		highRank.executeForm(robot);
		for (int i = 0; i < 10; i++) {
			RobotomyRequestForm robot2("target");
			midRank.signForm(robot2);
			highRank.executeForm(robot2);
		}
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nPresidential Pardon Form Exception:" << std::endl;
		PresidentialPardonForm pardon("Marvin");
		std::cout << pardon << std::endl;
		std::cout << "Should fail, low rank" << std::endl;
		midRank.signForm(pardon);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nPresidential Pardon Form Succes:" << std::endl;
		PresidentialPardonForm pardon("Marvin");
		std::cout << pardon << std::endl;
		highRank.signForm(pardon);
		std::cout << pardon << std::endl;
		highRank.executeForm(pardon);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nPresidential Pardon Form Exception:" << std::endl;
		PresidentialPardonForm pardon("Marvin");
		std::cout << pardon << std::endl;
		std::cout << "Should fail, not signed" << std::endl;
		highRank.executeForm(pardon);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
