#ifndef GRADETOOHIGHEXCEPTIONBASE_HPP
#define GRADETOOHIGHEXCEPTIONBASE_HPP

#include <iostream>
#include <exception>

class GradeTooHighExceptionBase : public std::exception {
private:
	// No private members;
public:
	virtual const char *what() const throw();
};

#endif
