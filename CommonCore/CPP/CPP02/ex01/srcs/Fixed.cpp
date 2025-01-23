#include "../includes/Fixed.hpp"

Fixed::Fixed() : _rawValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	if (value > (INT_MAX >> _fractionalBits)) {
		std::cerr << "***Error: Integer overflow***" << std::endl;
		_rawValue = INT_MAX;
	}
	else if (value < (INT_MIN >> _fractionalBits)) {
		std::cerr << "***Error: Integer underflow***" << std::endl;
		_rawValue = INT_MIN;
	}
	else
		_rawValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	double tmp = static_cast<double>(value * (1 << _fractionalBits));
	if (tmp > static_cast<double>(INT_MAX)) {
		std::cerr << "***Error: Float overflow***" << std::endl;
		_rawValue = INT_MAX;
	}
	else if (tmp < static_cast<double>(INT_MIN)) {
		std::cerr << "***Error: Float underflow***" << std::endl;
		_rawValue = INT_MIN;
	}
	else
		_rawValue = roundf(tmp);
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	_rawValue = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _rawValue;
}

void Fixed::setRawBits(int const raw) {
	_rawValue = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_rawValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _rawValue / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
