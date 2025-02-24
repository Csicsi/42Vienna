#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "GradeTooHighExceptionBase.hpp"
#include "GradeTooLowExceptionBase.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool _signed;
	const int _toSign;
	const int  _toExecute;

	virtual void action() const = 0;
public:
	AForm();
	AForm(const std::string name, const int toSign, const int toExecute);
	virtual ~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

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
