#ifndef NOTSIGNEDEXCEPTION_HPP
#define NOTSIGNEDEXCEPTION_HPP

#include <iostream>
#include <exception>

class NotSignedException {
private:
	// No private members;
public:
	virtual const char *what() const throw();
};

#endif
