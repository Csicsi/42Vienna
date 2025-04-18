#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <iterator>

template <typename T>
class PmergeMe {
private:
	int comparison_count;
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	int getComparisonCount() const;
	void sort(T &elements, int depth = 0);
};

#include "PmergeMe.tpp"

#endif
