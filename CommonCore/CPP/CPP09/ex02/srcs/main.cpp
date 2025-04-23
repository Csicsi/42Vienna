#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
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
	if (n <= 33)
		return maxComp[n];
	return static_cast<int>(n * std::log(n) / std::log(2) - 1.443 * n);
}

int main() {
	srand(static_cast<unsigned>(time(0)));

	const int TEST_RUNS = 100;
	const int MAX_LEN = 100;

	for (int len = 1; len <= MAX_LEN; ++len) {
		int failCount = 0;
		long long totalTime = 0;
		long long totalComparisons = 0;

		for (int test = 0; test < TEST_RUNS; ++test) {
			std::vector<int> raw(len);
			for (int i = 0; i < len; ++i)
				raw[i] = rand() % 10000;

			std::vector<int> vec = raw;
			std::vector<int> expected = raw;
			std::sort(expected.begin(), expected.end());

			PmergeMe<std::vector<int> > sorter;

			struct timeval start, end;
			gettimeofday(&start, NULL);
			sorter.sort(vec);
			gettimeofday(&end, NULL);

			long long elapsed = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
			totalTime += elapsed;
			totalComparisons += sorter.getComparisonCount();

			if (vec != expected)
				++failCount;
		}

		std::cout << "Length: " << len
		          << " | " << (failCount == 0 ? "✅" : "❌")
		          << " | Failures: " << failCount << "/" << TEST_RUNS
		          << " | Avg Time: " << (totalTime / TEST_RUNS) << " us"
		          << " | Avg Comparisons: " << (totalComparisons / TEST_RUNS)
		          << " | Max Comparisons: " << getMaxComparison(len)
		          << "\n";
	}

	return 0;
}
