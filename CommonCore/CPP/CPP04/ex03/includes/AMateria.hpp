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
	struct MateriaNode {
		AMateria* materia;
		MateriaNode* next;
	};
	static MateriaNode* _unequippedHead;
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
	static void cleanup();
	static void addToUnequippedList(AMateria* materia);
	static void cleanupUnequipped();
};

#endif
