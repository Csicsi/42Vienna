#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>
#include <algorithm>
#include <iostream>

#ifndef RESULT
#define RESULT 0
#endif

class PmergeMe {
private:
	int comparison_count;

	void createPairsVector(std::vector<int> &elements, size_t block_size);
	void mergeVector(const std::vector<int> &elements, size_t block_size,
			std::vector<int> &bigs, std::vector<int> &smalls);
	std::vector<size_t> jacobsthalVector(size_t pair_count) const;
	void binaryInsertVector(std::vector<int> &bigs,
			const std::vector<int> &smalls, size_t block_size);

	void createPairsDeque(std::deque<int> &elements, size_t block_size);
	void mergeDeque(const std::deque<int> &elements, size_t block_size,
			std::deque<int> &bigs, std::deque<int> &smalls);
	std::deque<size_t> jacobsthalDeque(size_t pair_count) const;
	void binaryInsertDeque(std::deque<int> &bigs,
			const std::deque<int> &smalls, size_t block_size);

	bool isJacobsthal(size_t n) const;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	int getComparisonCount() const;
	void setComparisonCount(int count);

	void sortVector(std::vector<int> &elements, size_t block_size = 1);
	void sortDeque(std::deque<int> &elements, size_t block_size = 1);
};

#endif
