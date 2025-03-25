#include <iostream>
#include "Array.hpp"

int main() {
	try {
		Array<int> empty;
		std::cout << "Empty array size: " << empty.size() << std::endl;

		Array<int> numbers(3);
		numbers[0] = 1;
		numbers[1] = 2;
		numbers[2] = 3;
		std::cout << "\nNumbers array size: " << numbers.size() << std::endl;

		Array<int> copy(numbers);
		numbers[0] = 99;

		std::cout << "\nOriginal numbers[0]: " << numbers[0] << std::endl;
		std::cout << "Copied array[0]: " << copy[0] << std::endl;

		std::cout << "\nTrying to access numbers[10]..." << std::endl;
		std::cout << numbers[10] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		Array<std::string> empty;
		std::cout << "\nEmpty array size: " << empty.size() << std::endl;

		Array<std::string> strings(3);
		strings[0] = "Hello";
		strings[1] = "World";
		strings[2] = "!";
		std::cout << "\nStrings array size: " << strings.size() << std::endl;
		for (std::size_t i = 0; i < strings.size(); ++i)
			std::cout << "strings[" << i << "]: " << strings[i] << std::endl;

		Array<std::string> copy(strings);
		strings[0] = "Goodbye";

		std::cout << "\nOriginal strings[0]: " << strings[0] << std::endl;
		std::cout << "Copied array[0]: " << copy[0] << std::endl;

		std::cout << "\nTrying to access strings[10]..." << std::endl;
		std::cout << strings[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Array<float> empty;
		std::cout << "\nEmpty array size: " << empty.size() << std::endl;

		Array<float> floats(3);
		floats[0] = 1.1f;
		floats[1] = 2.2f;
		floats[2] = 3.3f;

		std::cout << "\nFloats array size: " << floats.size() << std::endl;
		for (std::size_t i = 0; i < floats.size(); ++i)
			std::cout << "floats[" << i << "]: " << floats[i] << std::endl;

		Array<float> copy(floats);
		floats[0] = 99.9f;

		std::cout << "\nOriginal floats[0]: " << floats[0] << std::endl;
		std::cout << "Copied array[0]: " << copy[0] << std::endl;

		std::cout << "\nTrying to access floats[10]..." << std::endl;
		std::cout << floats[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
