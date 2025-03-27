#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
	try {
		int arr[] = {1, 2, 3, 4, 5};
		std::vector<int> vec(arr, arr + 5);
		std::cout << "Found in vector: " << *easyfind(vec, 2) << std::endl;

		std::list<int> lis(arr, arr + 5);
		std::cout << "Found in list: " << *easyfind(lis, 2) << std::endl;

		std::deque<int> deq(arr, arr + 5);
		std::cout << "Found in deque: " << *easyfind(deq, 2) << std::endl;

		std::cout << "Should throw:" << std::endl;
		std::cout << *easyfind(vec, 10) << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
