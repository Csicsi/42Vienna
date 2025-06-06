#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	const std::string _target;
	bool _signed;
	const int _toSign;
	const int  _toExecute;

	AForm();
	AForm &operator=(const AForm &other);

public:
	AForm(const std::string name, const std::string target, const int toSign, const int toExecute);
	virtual ~AForm();
	AForm(const AForm &other);

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class NotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	const std::string &getName() const;
	const std::string &getTarget() const;
	bool getSigned() const;
	void beSigned(const Bureaucrat &bureaucrat);
	int getToSign() const;
	int getToExecute() const;
	virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
