#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe() : comparison_count(0) {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &other)
	: comparison_count(other.comparison_count),
	  pair_history(other.pair_history) {}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->comparison_count = other.comparison_count;
		this->pair_history = other.pair_history;
	}
	return *this;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
int PmergeMe<T>::getComparisonCount() const {
	return comparison_count;
}

template <typename T>
const std::vector<std::vector<std::pair<int, int> > > &PmergeMe<T>::getPairHistory() const {
	return pair_history;
}

template <typename T>
void PmergeMe<T>::printPairHistory() const {
	for (size_t depth = 0; depth < pair_history.size(); ++depth) {
		std::cout << "Depth " << depth << ": ";
		for (size_t i = 0; i < pair_history[depth].size(); ++i) {
			std::cout << "(" << pair_history[depth][i].first << ", "
				<< pair_history[depth][i].second << ") ";
		}
		std::cout << std::endl;
	}
}

template <typename T>
void PmergeMe<T>::binaryInsert(T &sorted, int elem) {
	typename T::iterator left = sorted.begin();
	typename T::iterator right = sorted.end();

	while (left < right) {
		typename T::iterator mid = left + (right - left) / 2;
		++comparison_count;
		if (elem < *mid)
			right = mid;
		else
			left = mid + 1;
	}
	sorted.insert(left, elem);
}

template <typename T>
T PmergeMe<T>::getJacobsthal(int n) {
	T order;
	T jacob;
	jacob.push_back(1);
	jacob.push_back(3);

	while (true) {
		int next = jacob[jacob.size() - 1] * 2 + jacob[jacob.size() - 2];
		if (next >= n)
			break;
		jacob.push_back(next);
	}

	std::vector<bool> inserted(n, false);
	for (int i = static_cast<int>(jacob.size()) - 1; i >= 0; --i) {
		for (int j = jacob[i]; j > (i == 0 ? 0 : jacob[i - 1]); --j) {
			if ((j - 1) < n && !inserted[j - 1]) {
				order.push_back(j - 1);
				inserted[j - 1] = true;
			}
		}
	}
	if (n > 0 && !inserted[0])
		order.push_back(0);

	return order;
}

template <typename T>
void PmergeMe<T>::sort(T &elements) {
	if (elements.size() <= 1)
		return;

	T bigs, smalls;
	std::vector<std::pair<int, int> > current_pairs;

	typename T::iterator it = elements.begin();
	while (it + 1 < elements.end()) {
		int a = *it;
		int b = *(it + 1);
		current_pairs.push_back(std::make_pair(a, b));
		++comparison_count;
		if (a > b) {
			bigs.push_back(a);
			smalls.push_back(b);
		} else {
			bigs.push_back(b);
			smalls.push_back(a);
		}
		it += 2;
	}
	if (it != elements.end())
		smalls.push_back(*it);

	pair_history.push_back(current_pairs);
	sort(bigs);

	T result = bigs;

	T order = getJacobsthal(smalls.size());
	std::vector<bool> seen(smalls.size(), false);
	T full_order;

	for (size_t i = 0; i < order.size(); ++i) {
		if (order[i] < static_cast<int>(smalls.size()) && !seen[order[i]]) {
			full_order.push_back(order[i]);
			seen[order[i]] = true;
		}
	}
	for (size_t i = 0; i < smalls.size(); ++i) {
		if (!seen[i])
			full_order.push_back(i);
	}

	for (size_t i = 0; i < full_order.size(); ++i)
		binaryInsert(result, smalls[full_order[i]]);

	elements = result;
}

#endif
