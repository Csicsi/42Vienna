#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	btc.parseInputFile(argv[1]);
	btc.printData();

	return 0;
}
