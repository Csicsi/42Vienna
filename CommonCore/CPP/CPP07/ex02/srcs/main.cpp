#include <iostream>
#include "Array.hpp"

int main() {
	try {
		Array<int> empty;
		std::cout << "Empty array size: " << empty.size() << std::endl;

		Array<int> numbers(5);
		std::cout << "Numbers array size: " << numbers.size() << std::endl;

		for (unsigned int i = 0; i < numbers.size(); ++i)
			numbers[i] = (i * 10);

		Array<int> copy(numbers);
		numbers[0] = 99;

		std::cout << "Original numbers[0]: " << numbers[0] << std::endl;
		std::cout << "Copied array[0]: " << copy[0] << std::endl;

		std::cout << "Trying to access numbers[10]..." << std::endl;
		std::cout << numbers[10] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
