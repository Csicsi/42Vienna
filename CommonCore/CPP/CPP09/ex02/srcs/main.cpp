#include <sys/time.h>
#include <iostream>
#include <climits>
#include <cmath>
#include <cerrno>
#include "PmergeMe.hpp"

int getMaxComparison(int n) {
	static const int maxComp[] = {
		0, 0, 1, 3, 5, 7, 10, 13, 16, 19, 22,
		26, 30, 34, 38, 42, 46, 50, 54, 58, 62,
		66, 71, 76, 81, 86, 91, 96, 101, 106, 111,
		116, 121, 126, 131
	};
	if (n < 0)
		return 0;
	if (n <= 34)
		return maxComp[n];

	int sum = 0;
	for (int k = 1; k <= n; ++k) {
		sum += ceil(std::log(0.75 * k) / std::log(2.0));
	}
	return sum;
}

void parseArguments(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq) {
	if (argc < 2)
		throw std::invalid_argument("Error: No arguments provided.");

	for (int i = 1; i < argc; ++i) {
		std::string arg(argv[i]);

		for (size_t j = 0; j < arg.size(); ++j) {
			if (j == 0  && arg[j]  == '+')
				continue;
			if (!std::isdigit(arg[j]))
				throw std::invalid_argument("Error: Argument '" + arg
					+ "' is not a valid positive integer.");
		}

		char* endptr;
		errno = 0;
		long num = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || errno == ERANGE || num <= 0 || num > INT_MAX)
			throw std::invalid_argument("Error: Argument '" + arg
				+ "' is not a valid positive integer.");
		vec.push_back(static_cast<int>(num));
		deq.push_back(static_cast<int>(num));
	}
}

int main(int argc, char** argv) {
	std::vector<int> vec;
	std::deque<int> deq;

	try {
		parseArguments(argc, argv, vec, deq);
	} catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	PmergeMe sorter;
	struct timeval start, end;

	gettimeofday(&start, NULL);
	sorter.sortVector(vec);
	gettimeofday(&end, NULL);
	long long vecTime = (end.tv_sec - start.tv_sec) * 1000000LL
		+ (end.tv_usec - start.tv_usec);
	int vecComp = sorter.getComparisonCount();
	sorter.setComparisonCount(0);

	gettimeofday(&start, NULL);
	sorter.sortDeque(deq);
	gettimeofday(&end, NULL);
	long long deqTime = (end.tv_sec - start.tv_sec) * 1000000LL
		+ (end.tv_usec - start.tv_usec);
	int deqComp = sorter.getComparisonCount();

	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << " ";
	std::cout << "\n";

	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << "\n";

	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector: " << vecTime << " us\n";
	std::cout << "Time to process a range of " << deq.size()
		<< " elements with std::deque: " << deqTime << " us\n";

#if RESULT
	std::vector<int> expected(vec);
	std::sort(expected.begin(), expected.end());

	bool isSorted = (vec == expected);

	std::cout << (isSorted ? "\n[✅ Success] Vector sorted correctly.\n"
						   : "\n[❌ Error] Vector sort mismatch.\n");
	std::cout << "Comparison count for std::vector: " << vecComp << "\n";
	std::cout << "Comparison count for std::deque: " << deqComp << "\n";
	std::cout << "Max comparison count for " << vec.size() << " elements: "
		<< getMaxComparison(vec.size()) << "\n";
#else
	(void)vecComp;
	(void)deqComp;
#endif

	return 0;
}
