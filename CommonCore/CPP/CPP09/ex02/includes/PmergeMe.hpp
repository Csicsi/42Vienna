#ifndef MERGE_INSERT_SORTER_HPP
#define MERGE_INSERT_SORTER_HPP

#include <cstddef>
#include <vector>
#include <cmath>
#include <algorithm>

template <typename T>
class PmergeMe {
private:
	int comparison_count;

	void binaryInsert(T &sorted, int elem);
	T getJacobsthal(int n);
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	int getComparisonCount() const;
	void sort(T &elements);
};

#include "PmergeMe.tpp"

#endif
