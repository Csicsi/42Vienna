#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadExchangeRates() {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open data.csv");
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string::size_type pos = line.find(',');
		if (pos == std::string::npos) {
			throw std::runtime_error("Error: invalid data format");
		}
		std::string dateStr = line.substr(0, pos);
		std::string rateStr = line.substr(pos + 1);
		float rate = static_cast<float>(std::atof(rateStr.c_str()));
		if (rate < 0) {
			throw std::runtime_error("Error: negative exchange rate");
		}
		try {
			Date date(dateStr);
			_data[date] = rate;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
	}
}

void BitcoinExchange::processInputFile(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open data.csv");
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string::size_type pos = line.find('|');
		if (pos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string dateStr = line.substr(0, pos - 1);
		std::string valueStr = line.substr(pos + 1);
		float value = static_cast<float>(std::atof(valueStr.c_str()));
		if (value < 0) {
			std::cerr << "Error: not a positive number" << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: too large a number" << std::endl;
			continue;
		}
		if (valueStr.find_first_not_of("0123456789. ") != std::string::npos) {
			std::cerr << "Error: invalid value => " << valueStr << std::endl;
			continue;
		}
		try {
			Date date(dateStr);
			std::map<Date, float>::const_iterator it = _data.lower_bound(date);
			if (it == _data.end() || it->first != date) {
				if (it == _data.begin()) {
					std::cerr << "Error: no earlier data available for " << dateStr << std::endl;
					continue;
				}
				--it;
			}
			std::cout << dateStr << " => " << value << " = " << value * it->second << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
	}
	file.close();
}
