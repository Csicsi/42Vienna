#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	
public:
	PresidentialPardonForm(const std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);

	void execute(const Bureaucrat &executor) const;
};

#endif
