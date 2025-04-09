#include "Span.hpp"
#include <iostream>
#include <ctime>

int main() {
	std::cout << "******* Subject Tests *******" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "\n******* Overflow Test *******" << std::endl;
	{
		try {
			Span sp = Span(1);
			sp.addNumber(1);
			std::cout << "Should throw: " << std::endl;
			sp.addNumber(2);
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n******* Not Enough Numbers Test *******" << std::endl;
	{
		try {
			Span sp = Span(1);
			sp.addNumber(1);
			std::cout << "Should throw: " << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n******* Large Test *******" << std::endl;
	{
		Span sp = Span(10000);
		for (int i = 0; i < 10000; ++i) {
			sp.addNumber(i);
		}
		std::cout << "Should be 1: " << sp.shortestSpan() << std::endl;
		std::cout << "Should be 9999: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n******* Random Test *******" << std::endl;
	{
		Span sp = Span(1000);
		std::vector<int> nums;
		std::srand(std::time(NULL));
		for (int i = 0; i < 1000; ++i)
			nums.push_back(std::rand());

		sp.addNumbers(nums.begin(), nums.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n******* Range Insertion Test *******" << std::endl;
	{
		int arr[] = {1, 5, 3, 10, 100};
		std::vector<int> vec(arr, arr + 5);
		Span sp(vec.size());

		sp.addNumbers(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n******* Copy Constructor Test *******" << std::endl;
	{
		Span sp1 = Span(2);
		sp1.addNumber(1);
		sp1.addNumber(2);

		Span sp2 = Span(sp1);
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}

	std::cout << "\n******* Assignment Operator Test *******" << std::endl;
	{
		Span sp1 = Span(2);
		sp1.addNumber(1);
		sp1.addNumber(2);

		Span sp2 = Span(2);
		sp2 = sp1;
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
}
