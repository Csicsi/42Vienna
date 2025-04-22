#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include "PmergeMe.hpp"

int getMaxComparison(int n) {
	static const int maxComp[] = {
		0, 1, 3, 5, 7, 10, 13, 16, 19, 22,
		26, 30, 34, 38, 42, 46, 50, 54, 58, 62,
		66, 71, 76, 81, 86, 91, 96, 101, 106, 111,
		116, 121, 126, 131
	};
	if (n < 0)
		return 0;
	if (n <= 33)
		return maxComp[n];
	return static_cast<int>(n * std::log(n) / std::log(2) - 1.443 * n);
}

int main() {
	srand(static_cast<unsigned>(time(0)));

	const size_t len = 19;
	int raw[len];
	for (size_t i = 0; i < len; ++i)
		raw[i] = rand() % 100;

	std::vector<int> vec(raw, raw + len);
	std::deque<int> deq(raw, raw + len);

	PmergeMe<std::vector<int> > vecSorter;
	//PmergeMe<std::deque<int> > deqSorter;

	struct timeval start, end;

	gettimeofday(&start, NULL);
	vecSorter.sort(vec);
	gettimeofday(&end, NULL);
	long long vecTime = (end.tv_sec - start.tv_sec) * 1000000LL
	+ (end.tv_usec - start.tv_usec);

	/*gettimeofday(&start, NULL);
	deqSorter.sort(deq);
	gettimeofday(&end, NULL);
	long long deqTime = (end.tv_sec - start.tv_sec) * 1000000LL
	+ (end.tv_usec - start.tv_usec);*/

	std::vector<int> expected(raw, raw + len);
	std::sort(expected.begin(), expected.end());

	std::cout << "Before: ";
	for (size_t i = 0; i < len; ++i)
		std::cout << raw[i] << " ";

	std::cout << "\nAfter: ";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
		if (vec[i] != expected[i]) {
			std::cerr << "\n[Error] Vector sort mismatch.\n";
			return 1;
		}
	}

	std::cout << "\nTime to process a range of " << len << " elements with std::vector: " << vecTime << " us\n";
	//std::cout << "Time to process a range of " << len << " elements with std::deque: " << deqTime << " us\n";

	std::cout << "Comparison count for std::vector: " << vecSorter.getComparisonCount() << "\n";
	//std::cout << "Comparison count for std::deque: " << deqSorter.getComparisonCount() << "\n";
	std::cout << "Max comparison count for " << len << " elements: " << getMaxComparison(len) << "\n";
	return 0;
}
