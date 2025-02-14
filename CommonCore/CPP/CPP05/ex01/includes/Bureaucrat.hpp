#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
	const std::string _name;
	int _grade;

public:
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	std::string getName() const;
	int getGrade() const;
	void incrementGrade(int num);
	void decrementGrade(int num);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
