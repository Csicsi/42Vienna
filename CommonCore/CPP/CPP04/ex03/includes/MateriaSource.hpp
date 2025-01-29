#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria *_materia[4];
	void _deleteMateria();
	void _copyMateria(const MateriaSource &other);
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};

#endif
