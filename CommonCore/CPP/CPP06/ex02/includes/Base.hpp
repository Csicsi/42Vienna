#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <exception>

class Base {
public:
	virtual ~Base();

	void identify(Base *p);
	void identify(Base &p);
};

#endif
