#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <iterator>


#ifndef DEBUG
#define DEBUG 0
#endif

template <typename T>
class PmergeMe {
private:
	int comparison_count;
	size_t container_size;

	void createPairs(T &elements, size_t block_size);
	void merge(const T& elements, size_t block_size, T& merged, T& smalls);
	std::vector<size_t> jacobsthal(size_t pair_count);
	void binaryInsert(T& bigs, const T& smalls, const T& elements, size_t block_size);
	size_t insertLeftovers(T& bigs, const T& elements, size_t block_size, size_t leftover_start);
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	int getComparisonCount() const;
	void sort(T &elements, size_t block_size = 1);
};

#include "PmergeMe.tpp"

#endif
