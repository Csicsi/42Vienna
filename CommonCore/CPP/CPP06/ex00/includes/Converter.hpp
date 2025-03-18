#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <cfloat>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <cerrno>
#include <limits>

class Converter {
private:
	Converter();
	~Converter();
	Converter(const Converter &other);
	Converter &operator=(const Converter &other);
public:
	static void convert(std::string const &literal);
};

bool isChar(std::string const &literal);
bool isInt(std::string const &literal);
bool isFloat(std::string const &literal, bool recursive = false);
bool isDouble(std::string const &literal);

#endif
