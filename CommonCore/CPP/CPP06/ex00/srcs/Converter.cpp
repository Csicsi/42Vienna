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
	std::stringstream ss(literal);
	unsigned int i;

	ss >> i;
	return (ss.eof() && !ss.fail());
}

bool Converter::isFloat(const std::string &literal) {
	std::stringstream ss(literal);
	float f;

	ss >> f;
	return (ss.eof() && !ss.fail());
}

bool Converter::isDouble(const std::string &literal) {
	std::stringstream ss(literal);
	double d;

	ss >> d;
	return (ss.eof() && !ss.fail());
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
