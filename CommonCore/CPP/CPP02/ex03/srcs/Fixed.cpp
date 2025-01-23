#include "../includes/Fixed.hpp"

Fixed::Fixed() : _rawValue(0) {}
Fixed::Fixed(const Fixed &fixed) {*this = fixed;}
Fixed &Fixed::operator=(const Fixed &fixed) {
	_rawValue = fixed.getRawBits();
	return *this;
}
Fixed::~Fixed() {}

Fixed::Fixed(const int value) {
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

int Fixed::getRawBits(void) const {return _rawValue;}
void Fixed::setRawBits(int const raw) {_rawValue = raw;}

float Fixed::toFloat(void) const {
	return static_cast<float>(_rawValue) / (1 << _fractionalBits);
}
int Fixed::toInt(void) const {return _rawValue / (1 << _fractionalBits);}

bool Fixed::operator>(const Fixed &fixed) const {return _rawValue > fixed.getRawBits();}
bool Fixed::operator<(const Fixed &fixed) const {return _rawValue < fixed.getRawBits();}
bool Fixed::operator>=(const Fixed &fixed) const {return _rawValue >= fixed.getRawBits();}
bool Fixed::operator<=(const Fixed &fixed) const {return _rawValue <= fixed.getRawBits();}
bool Fixed::operator==(const Fixed &fixed) const {return _rawValue == fixed.getRawBits();}
bool Fixed::operator!=(const Fixed &fixed) const {return _rawValue != fixed.getRawBits();}

Fixed Fixed::operator+(const Fixed &fixed) const {
	Fixed tmp;
	tmp.setRawBits(_rawValue + fixed.getRawBits());
	return tmp;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	Fixed tmp;
	tmp.setRawBits(_rawValue - fixed.getRawBits());
	return tmp;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	Fixed tmp;
	tmp.setRawBits((_rawValue * fixed.getRawBits()) >> _fractionalBits);
	return tmp;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	Fixed tmp;
	tmp.setRawBits((_rawValue << _fractionalBits) / fixed.getRawBits());
	return tmp;
}

Fixed &Fixed::operator++() {
	_rawValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--() {
	_rawValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {return a < b ? a : b;}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {return a < b ? a : b;}
Fixed &Fixed::max(Fixed &a, Fixed &b) {return a > b ? a : b;}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {return a > b ? a : b;}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
