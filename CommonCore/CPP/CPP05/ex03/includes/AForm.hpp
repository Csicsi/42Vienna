#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "GradeTooHighExceptionBase.hpp"
#include "GradeTooLowExceptionBase.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

typedef class AForm Form;

class AForm {
private:
	const std::string _name;
	const std::string _target;
	bool _signed;
	const int _toSign;
	const int  _toExecute;
public:
	AForm();
	AForm(const std::string name, const std::string target, const int toSign, const int toExecute);
	virtual ~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

	class GradeTooHighException : public GradeTooHighExceptionBase {};
	class GradeTooLowException : public GradeTooLowExceptionBase {};

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
