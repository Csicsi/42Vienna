#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

class Bureaucrat {
private:
	const std::string _name;
	int _grade;

	Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& other);

public:
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);

	std::string getName() const;
	int getGrade() const;
	void incrementGrade(int num);
	void decrementGrade(int num);

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
