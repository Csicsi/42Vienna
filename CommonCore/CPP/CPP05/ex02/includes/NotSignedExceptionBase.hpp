#ifndef NOTSIGNEDEXCEPTIONBASE_HPP
#define NOTSIGNEDEXCEPTIONBASE_HPP

#include <iostream>
#include <exception>

class NotSignedExceptionBase : public std::exception {
private:
	// No private members;
public:
	virtual const char *what() const throw();
};

#endif
