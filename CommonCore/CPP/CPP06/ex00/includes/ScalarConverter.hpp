#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <cmath>

class ScalarConverter {
private:

	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
public:
	static void convert(std::string const &literal);
};

bool isChar(std::string const &literal);
bool isInt(std::string const &literal);
bool isFloat(std::string const &literal, bool recursive = false);
bool isDouble(std::string const &literal);

void printChar(double value);
void printInt(double value);
void printFloat(double value);
void printDouble(double value);

#endif
