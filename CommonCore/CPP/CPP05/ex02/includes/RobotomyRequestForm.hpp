#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
private:
	// No private members;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	void execute(const Bureaucrat &executor) const;
};

#endif
