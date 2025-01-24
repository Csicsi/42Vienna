#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10),
	_energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name),
	_hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap assignation operator called"
		<< std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(std::string const &target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage
			<< " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " cannot attack!"
			<< std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " has died!"
			<< std::endl;
	} else {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes "
			<< amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " is repaired for "
			<< amount << " points!" << std::endl;
		_hitPoints += amount;
	} else {
		std::cout << "ClapTrap " << _name << " cannot be repaired!"
			<< std::endl;
	}
}

