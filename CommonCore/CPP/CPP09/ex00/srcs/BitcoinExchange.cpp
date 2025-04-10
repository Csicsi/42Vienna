#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseInputFile(const std::string& filename) {
	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(infile, line);
	if (line != "date | value") {
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}

	while (std::getline(infile, line)) {
		std::istringstream ss(line);
		std::string dateStr, valueStr;

		if (line.find(" | ") == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		dateStr = line.substr(0, line.find(" | "));
		valueStr = line.substr(line.find(" | ") + 3);

		std::cout << "Date: " << dateStr << ", Value: " << valueStr << std::endl;
		bool valid = true;

		for (int i = 0; i < 10; ++i) {
			char c = dateStr[i];
			switch (i) {
				case 4:
				case 7:
					if (c != '-') {
						valid = false;
					}
					break;
				default:
					if (!isdigit(c)) {
						valid = false;
					}
					break;
			}
			if (!valid)
				break;
		}

		if (!valid) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
	}
}

void BitcoinExchange::printData() const {
	return;
}
