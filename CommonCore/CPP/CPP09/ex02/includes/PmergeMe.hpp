#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iostream>

template <typename T>
class PmergeMe {
private:
	int comparison_count;
	std::vector<std::vector<std::pair<int, int> > > pair_history;

	void binaryInsert(T &sorted, int elem);
	T getJacobsthal(int n);
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	int getComparisonCount() const;
	const std::vector<std::vector<std::pair<int, int> > > &getPairHistory() const;
	void printPairHistory() const;
	void sort(T &elements);
};

#include "PmergeMe.tpp"

#endif
