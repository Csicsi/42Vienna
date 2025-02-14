#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
protected:
	std::string _type;

private:
	static AMateria* _head;
	AMateria* _next;
public:
	AMateria();
	AMateria(std::string const &type);
	virtual ~AMateria();
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);

	std::string const &getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter &target);

	static void* operator new(size_t size);
	static void operator delete(void* ptr);
	static void addToList(AMateria* materia);
	static void cleanup();
};

#endif
