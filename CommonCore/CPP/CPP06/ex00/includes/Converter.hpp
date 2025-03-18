#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <climits>
#include <cstdlib>
#include <cfloat>
#include <sstream>

class Converter {
private:
	Converter();
	~Converter();
	Converter(const Converter &other);
	Converter &operator=(const Converter &other);

	static bool isChar(std::string const &literal);
	static bool isInt(std::string const &literal);
	static bool isFloat(std::string const &literal);
	static bool isDouble(std::string const &literal);
public:
	static void convert(std::string const &literal);
};

#endif
