#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal {
private:
	std::string type;
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);

	void makeSound() const;
};

#endif
