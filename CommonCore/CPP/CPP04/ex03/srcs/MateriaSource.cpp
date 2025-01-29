#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	//_deleteMateria();
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	_copyMateria(other);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	std::cout << "MateriaSource assignation operator called"
		<< std::endl;
	if (this != &other) {
		_deleteMateria();
		_copyMateria(other);
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++) {
		if (_materia[i] == NULL) {
			_materia[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materia[i] != NULL && _materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return NULL;
}

void MateriaSource::_deleteMateria() {
	for (int i = 0; i < 4; i++) {
		if (_materia[i] != NULL) {
			delete _materia[i];
			_materia[i] = NULL;
		}
	}
}

void MateriaSource::_copyMateria(const MateriaSource &other) {
	for (int i = 0; i < 4; i++) {
		if (other._materia[i] != NULL)
			_materia[i] = other._materia[i]->clone();
		else
			_materia[i] = NULL;
	}
}
