#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 2);
		Bureaucrat jim("Jim", 150);
		std::cout << bob << std::endl;
		Form form("Form", 10, 1);
		std::cout << form << std::endl;
		form.beSigned(bob);
		std::cout << form << std::endl;
		Form form2("Form2", 100, 1);
		bob.signForm(form2);
		std::cout << form2 << std::endl;
		jim.signForm(form2);
		std::cout << form2 << std::endl;
		Form form3("Form3", 10, 1);
		jim.signForm(form3);
		std::cout << form3 << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
