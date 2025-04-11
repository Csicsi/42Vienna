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
	void loadExchangeRates();
	void processInputFile(const std::string& filename);
};

#endif
