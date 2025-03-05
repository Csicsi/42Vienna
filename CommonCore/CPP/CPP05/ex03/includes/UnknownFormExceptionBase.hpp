#ifndef UNKNOWNFORMEXCEPTIONBASE_HPP
#define UNKNOWNFORMEXCEPTIONBASE_HPP

#include <iostream>
#include <exception>

class UnknownFormExceptionBase : public std::exception {
private:
	// No private members;
public:
	virtual const char *what() const throw();
};

#endif
