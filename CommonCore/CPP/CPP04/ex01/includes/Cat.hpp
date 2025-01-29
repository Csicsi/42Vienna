#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	std::string _type;
	Brain *brain;
public:
	Cat();
	~Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);

	void makeSound() const;
	void setIdea(const std::string &idea, int index);
	std::string getIdea(int index) const;
};

#endif
