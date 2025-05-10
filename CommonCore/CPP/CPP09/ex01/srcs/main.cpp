#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: invalid argument" << std::endl;
		std::cerr << "Usage: ./rpn \"<expression>\"" << std::endl;
		return 1;
	}

	RPN rpn;
	try {
		rpn.compute(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
