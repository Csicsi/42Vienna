#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: invalid argument" << std::endl;
		std::cerr << "Usage: ./rpn \"<expression>\"" << std::endl;
		return 1;
	}

	RPN rpn;
	rpn.compute(argv[1]);
	return 0;
}
