#include "iter.hpp"
#include <iostream>

template <typename T>
void printElement(const T& element) {
	std::cout << element << " ";
}

void increment(int& n) {
	n += 1;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	size_t size = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Original array: ";
	iter(arr, size, printElement<int>);
	std::cout << std::endl;

	iter(arr, size, increment);

	std::cout << "After increment: ";
	iter(arr, size, printElement<int>);
	std::cout << std::endl;

	std::string strArr[] = {"Hello", "42", "Vienna"};
	std::cout << "String array: ";
	iter(strArr, 3, printElement<std::string>);
	std::cout << std::endl;

	float fltArr[] = {1.1f, 2.2f, 3.3f};
	std::cout << "Float array: ";
	iter(fltArr, 3, printElement<float>);
	std::cout << std::endl;

	char charArr[] = {'a', 'b', 'c'};
	std::cout << "Char array: ";
	iter(charArr, 3, printElement<char>);
	std::cout << std::endl;

	return 0;
}
