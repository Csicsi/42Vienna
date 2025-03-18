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

bool isChar(const std::string &literal) {
	return (literal.length() == 1 && !isdigit(literal[0]) && isprint(literal[0]));
}

bool isInt(const std::string &literal) {
	if (literal.empty())
		return false;

	char *endptr;
	errno = 0;
	long l = std::strtol(literal.c_str(), &endptr, 10);

	if (*endptr != '\0' || errno == ERANGE || l < INT_MIN || l > INT_MAX)
		return false;
	return true;
}

bool isFloat(const std::string &literal, bool recursive) {
	if (literal.empty() || literal == "f")
		return false;
	if (literal[literal.length() - 1] == 'f' && !recursive) {
		return isFloat(literal.substr(0, literal.length() - 1), true);
	}
	char *endptr;
	errno = 0;
	float f = std::strtof(literal.c_str(), &endptr);
	if (*endptr != '\0' || errno == ERANGE)
		return false;
	(void)f;

	double d = std::strtod(literal.c_str(), &endptr);
	if ((literal != "inf" && literal != "-inf" && literal != "+inf")
		&& (d < -std::numeric_limits<float>::max()
		|| d > std::numeric_limits<float>::max()))
		return false;

	return true;
}

bool isDouble(const std::string &literal) {
	if (literal.empty())
		return false;

	char *endptr;
	errno = 0;
	double d = std::strtod(literal.c_str(), &endptr);
	(void)d;

	if (*endptr != '\0' || errno == ERANGE)
		return false;

	return true;
}


void Converter::convert(const std::string &literal) {
	char c;
	int i;
	float f;
	double d;

	if (isChar(literal)) {
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (isInt(literal)) {
		i = std::atoi(literal.c_str());
		c = (i >= 32 && i <= 126) ? static_cast<char>(i) : 0;
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}
	else if (isFloat(literal)) {
		f = std::strtof(literal.c_str(), NULL);
		i = static_cast<int>(f);
		c = (i >= 32 && i <= 126) ? static_cast<char>(i) : 0;
		d = static_cast<double>(f);
	}
	else if (isDouble(literal)) {
		d = std::strtod(literal.c_str(), NULL);
		i = static_cast<int>(d);
		c = (i >= 32 && i <= 126) ? static_cast<char>(i) : 0;
		f = static_cast<float>(d);
	}
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else if (isInt(literal) || isFloat(literal) || isDouble(literal))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	if (isInt(literal) || isFloat(literal) || isDouble(literal))
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if (isFloat(literal) || isInt(literal) || isDouble(literal)) {
		std::cout << "float: " << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	} else
		std::cout << "float: impossible" << std::endl;

	if (isDouble(literal) || isFloat(literal) || isInt(literal)) {
		std::cout << "double: " << d;
		if (d == static_cast<int>(d))
			std::cout << ".0";
		std::cout << std::endl;
	} else
		std::cout << "double: impossible" << std::endl;
}
