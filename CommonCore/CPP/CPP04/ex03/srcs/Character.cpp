#include "Character.hpp"

Character::Character() {
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name) {
	std::cout << "Character parameter constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	_deleteInventory();
}

Character::Character(const Character &other) {
	std::cout << "Character copy constructor called" << std::endl;
	_copyInventory(other);
}

Character &Character::operator=(const Character &other) {
	std::cout << "Character assignation operator called"
		<< std::endl;
	if (this != &other) {
		_deleteInventory();
		_name = other._name;
		_copyInventory(other);
	}
	return *this;
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == m)
			return;
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || _inventory[idx] == NULL)
		return;
	AMateria::addToList(_inventory[idx]);
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= 4 || _inventory[idx] == NULL)
		return;
	_inventory[idx]->use(target);
}

void Character::_deleteInventory() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

void Character::_copyInventory(const Character &other) {
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i] != NULL)
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}
