#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include "Date.hpp"

class BitcoinExchange {
private:
	std::map<Date, float> _data;

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	void loadExchangeRates();
	void processInputFile(const std::string& filename);
};

#endif
