#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

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

std::string BitcoinExchange::validateValueStr(const std::string& valueStr) {
	std::string result;
	if (valueStr.empty() || valueStr.substr(1).empty()) {
		std::cerr << "Error: empty value" << std::endl;
		return result;
	}
	if (valueStr[0] != ' ') {
		std::cerr << "Error: invalid format" << std::endl;
		return result;
	}
	int i = 1;
	if (valueStr[1] == '+' || valueStr[1] == '-')
		i++;
	if (valueStr.substr(i).find_first_not_of("0123456789.") != std::string::npos) {
		std::cerr << "Error: invalid value => " << valueStr << std::endl;
		return result;
	}
	std::string::size_type pos = valueStr.find('.');
	std::string::size_type pos2 = valueStr.substr(pos + 1).find('.');
	if (pos2 != std::string::npos) {
		std::cerr << "Error: invalid value => " << valueStr << std::endl;
		return result;
	}
	result = valueStr;
	return result;
}

bool BitcoinExchange::validateValue(const std::string& valueStr, float value) {
	if (value < 0) {
		std::cerr << "Error: not a positive number" << std::endl;
		return false;
	}
	if (value > 1000) {
		std::cerr << "Error: too large a number" << std::endl;
		return false;
	}
	if (value == 1000 && valueStr.substr(2).find_first_not_of("0.")
		!= std::string::npos) {
		std::cerr << "Error: too large a number" << std::endl;
		return false;
	}
	return true;
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
		std::string valueStr = validateValueStr(line.substr(pos + 1));
		if (valueStr.empty()) {
			continue;
		}
		float value = static_cast<float>(std::atof(valueStr.c_str()));
		if (!validateValue(valueStr, value)) {
			continue;
		}
		try {
			Date date(dateStr);
			std::map<Date, float>::const_iterator it = _data.lower_bound(date);
			if (it == _data.end() || it->first != date) {
				if (it == _data.begin()) {
					std::cerr << "Error: no earlier data available for "
						<< dateStr << std::endl;
					continue;
				}
				--it;
			}
			std::cout << dateStr << " => " << value << " = "
				<< value * it->second << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
	}
	file.close();
}
