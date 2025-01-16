#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>

bool getInput(const std::string &prompt, std::string &input);
bool getValidatedPhoneNumber(const std::string &prompt,
	std::string &phoneNumber);
bool isValidIndex(const std::string &input, int &index);
std::string turncate(std::string src);
size_t ft_strlen(const std::string& str);

#endif
