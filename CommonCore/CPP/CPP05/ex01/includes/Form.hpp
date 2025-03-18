#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
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

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	const std::string &getName() const;
	bool getSigned() const;
	void beSigned(const Bureaucrat &bureaucrat);
	int getToSign() const;
	int getToExecute() const;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
