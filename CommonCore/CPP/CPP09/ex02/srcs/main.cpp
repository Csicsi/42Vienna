#include <sys/time.h>
#include <iostream>
#include <climits>
#include <cmath>
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
	if (argc < 2) {
		std::cerr << "Error: Please provide at least one positive integer as an argument.\n";
		std::exit(1);
	}

	for (int i = 1; i < argc; ++i) {
		std::string arg(argv[i]);

		for (size_t j = 0; j < arg.size(); ++j) {
			if (j == 0  && arg[j]  == '+')
				continue;
			if (!std::isdigit(arg[j])) {
				std::cerr << "Error: Argument '" << arg
					<< "' is not a positive integer.\n";
				std::exit(1);
			}
		}

		long num = std::strtol(argv[i], NULL, 10);

		if (num <= 0 || num > INT_MAX) {
			std::cerr << "Error: Argument '" << arg
				<< "' is not a valid positive integer.\n";
			std::exit(1);
		}

		vec.push_back(static_cast<int>(num));
		deq.push_back(static_cast<int>(num));
	}
}

int main(int argc, char** argv) {
	std::vector<int> vec;
	std::deque<int> deq;

	parseArguments(argc, argv, vec, deq);

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
