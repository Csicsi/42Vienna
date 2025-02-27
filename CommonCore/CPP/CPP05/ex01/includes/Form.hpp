#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "GradeTooHighExceptionBase.hpp"
#include "GradeTooLowExceptionBase.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string _name;
	bool _signed;
	const int _toSign;
	const int  _toExecute;
public:
	Form();
	Form(const std::string name, const int toSign, const int toExecute);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

	class GradeTooHighException : public GradeTooHighExceptionBase {};
	class GradeTooLowException : public GradeTooLowExceptionBase {};

	const std::string &getName() const;
	bool getSigned() const;
	void beSigned(const Bureaucrat &bureaucrat);
	int getToSign() const;
	int getToExecute() const;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
