#include "AMateria.hpp"

AMateria* AMateria::_head = NULL;

AMateria::AMateria() : _next(NULL) {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type), _next(NULL) {
	std::cout << "AMateria parameter constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) {
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
	std::cout << "AMateria assignation operator called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	(void)target;
}

AMateria* AMateria::clone() const {
	return NULL;
}

void* AMateria::operator new(size_t size) {
	void* ptr = ::operator new(size);
	AMateria* newMateria = static_cast<AMateria*>(ptr);

	newMateria->_next = _head;
	_head = newMateria;

	std::cout << "AMateria allocated and added to list" << std::endl;
	return ptr;
}

void AMateria::operator delete(void* ptr) {
	AMateria* materia = static_cast<AMateria*>(ptr);

	if (_head == materia) {
		_head = _head->_next;
	} else {
		AMateria* prev = _head;
		while (prev && prev->_next != materia) {
			prev = prev->_next;
		}
		if (prev) {
			prev->_next = materia->_next;
		}
	}

	std::cout << "AMateria deallocated and removed from list" << std::endl;
	::operator delete(ptr);
}

void AMateria::cleanup() {
	while (_head) {
		AMateria* tmp = _head;
		_head = _head->_next;
		delete tmp;
	}
	std::cout << "All AMateria instances freed" << std::endl;
}

void AMateria::addToList(AMateria* materia) {
	materia->_next = _head;
	_head = materia;
}
