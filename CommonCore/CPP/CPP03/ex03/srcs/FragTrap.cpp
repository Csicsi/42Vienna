#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap") {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		_energyPoints--;
		std::cout << "FragTrap " << _name << " says: \"High five!\"" << std::endl;
	} else {
		std::cout << "FragTrap " << _name << " Cannot high five!" << std::endl;
	}
}
