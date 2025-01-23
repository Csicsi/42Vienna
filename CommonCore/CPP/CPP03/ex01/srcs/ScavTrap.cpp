#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ScavTrap " << _name << " Cannot attack!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode!" << std::endl;
}


