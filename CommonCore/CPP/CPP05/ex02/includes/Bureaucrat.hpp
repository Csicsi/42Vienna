#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "GradeTooHighExceptionBase.hpp"
#include "GradeTooLowExceptionBase.hpp"
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);


	std::string getName() const;
	int getGrade() const;
	void incrementGrade(int num);
	void decrementGrade(int num);
	void signForm(Form &Form);

	class GradeTooHighException : public GradeTooHighExceptionBase {};
	class GradeTooLowException : public GradeTooLowExceptionBase {};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
