#include "Converter.hpp"

Converter::Converter() {
	std::cout << "Converter default constructor called" << std::endl;
}

Converter::~Converter() {
	std::cout << "Converter destructor called" << std::endl;
}

Converter::Converter(const Converter &other) {
	std::cout << "Converter copy constructor called" << std::endl;
	*this = other;
}

Converter &Converter::operator=(const Converter &other) {
	std::cout << "Converter assignation operator called"
		<< std::endl;
	(void)other;
	return *this;
}

bool Converter::isChar(const std::string &literal) {
	return (literal.length() == 1 && !isdigit(literal[0]));
}

bool Converter::isInt(const std::string &literal) {
	if (literal.empty())
		return false;
	for (size_t i = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
		i < literal.length(); i++) {
		if (!isdigit(literal[i])) return false;
	}
	long l = std::strtol(literal.c_str(), NULL, 10);
	if (l > INT_MAX || l < INT_MIN)
		return false;
	return true;
}

bool Converter::isFloat(const std::string &literal) {
	if (literal.empty())
		return false;
	size_t dot = 0;
	size_t len = literal.length();
	if (literal[len - 1] != 'f')
		return false;
	for (size_t i = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
		i < len - 1; i++) {
		if (literal[i] == '.') {
			if (++dot > 1) {
				return false;
			}
		} else if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

bool Converter::isDouble(const std::string &literal) {
	if (literal.empty())
		return false;
	size_t dot = 0;
	size_t len = literal.length();
	if (literal[len - 1] == 'f')
		return false;
	for (size_t i = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
		i < len; i++) {
		if (literal[i] == '.') {
			if (++dot > 1) {
				return false;
			}
		} else if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

void Converter::convert(const std::string &literal) {
	if (isChar(literal))
		std::cout << "char" << std::endl;
	else if (isInt(literal))
		std::cout << "int" << std::endl;
	else if (isFloat(literal))
		std::cout << "float" << std::endl;
	else if (isDouble(literal))
		std::cout << "double" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}
