#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 2);
		ShrubberyCreationForm form("home");
		bob.signForm(form);
		form.execute(bob);
		RobotomyRequestForm form2("robot");
		bob.signForm(form2);
		form2.execute(bob);
		PresidentialPardonForm form3("target");
		bob.signForm(form3);
		form3.execute(bob);
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
