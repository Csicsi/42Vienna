#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	try {
		btc.loadExchangeRates();
		btc.processInputFile(argv[1]);
	} catch (const std::runtime_error& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
