#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
public:
	Animal();
	~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

private:
	std::string type;
};

#endif
