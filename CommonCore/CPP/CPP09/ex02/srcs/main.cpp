#include <cstdlib>
#include <ctime>
#include <cmath>
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
	if (n <= 34)
		return maxComp[n];

	int sum = 0;
	for (int k = 1; k <= n; ++k) {
		sum += ceil(std::log(0.75 * k) / std::log(2.0));
	}
	return sum;
}

int main() {
	srand(static_cast<unsigned>(time(0)));

	const size_t len = 20;
	int raw[len];
	for (size_t i = 0; i < len; ++i)
		raw[i] = rand() % 100;

	std::vector<int> vec(raw, raw + len);
	std::deque<int> deq(raw, raw + len);

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
	for (size_t i = 0; i < len; ++i)
		std::cout << raw[i] << " ";

	std::cout << "\nAfter: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";

	std::cout << "\nTime to process a range of " << len << " elements with std::vector: " << vecTime << " us\n";
	std::cout << "Time to process a range of " << len << " elements with std::deque: " << deqTime << " us\n";

#if RESULT

	std::vector<int> expected(raw, raw + len);
	std::sort(expected.begin(), expected.end());

	bool isSorted = (vec == expected);

	std::cout << (isSorted ? "\n[✅ Success] Vector sorted correctly.\n"
						  : "\n[❌ Error] Vector sort mismatch.\n");
	std::cout << "Comparison count for std::vector: " << vecComp << "\n";
	std::cout << "Comparison count for std::deque: " << deqComp << "\n";
	std::cout << "Max comparison count for " << len << " elements: " << getMaxComparison(len) << "\n";

#else

	(void)vecComp;
	(void)deqComp;

#endif

	return 0;
}
