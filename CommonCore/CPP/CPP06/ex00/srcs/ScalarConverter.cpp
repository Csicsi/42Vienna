#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	std::cout << "ScalarConverter assignation operator called"
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

void printChar(double value) {
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void printInt(double value) {
	if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void printFloat(double value) {
	float f = static_cast<float>(value);
	std::cout << "float: " << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void printDouble(double value) {
	std::cout << "double: " << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
	if (isChar(literal)) {
		char c = literal[0];
		double value = static_cast<double>(c);
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
		return;
	}

	double value;
	if (isInt(literal)) {
		value = static_cast<double>(std::atoi(literal.c_str()));
	} else if (isFloat(literal)) {
		value = static_cast<double>(std::strtof(literal.c_str(), NULL));
	} else if (isDouble(literal)) {
		value = std::strtod(literal.c_str(), NULL);
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
