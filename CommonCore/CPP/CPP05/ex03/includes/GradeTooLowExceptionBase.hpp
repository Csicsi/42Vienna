#ifndef GRADETOOLOWEXCEPTIONBASE_HPP
#define GRADETOOLOWEXCEPTIONBASE_HPP

#include <iostream>
#include <exception>

class GradeTooLowExceptionBase : public std::exception {
private:
	// No private members;
public:
	virtual const char *what() const throw();
};

#endif
