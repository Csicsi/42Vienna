#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe() : comparison_count(0) {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &other)
	: comparison_count(other.comparison_count) {}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &other) {
	if (this != &other)
		this->comparison_count = other.comparison_count;
	return *this;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
int PmergeMe<T>::getComparisonCount() const {
	return comparison_count;
}
template <typename T>
void PmergeMe<T>::sort(T &elements, int depth) {
	if (elements.size() <= 1)
		return;

	size_t block_size = static_cast<size_t>(std::pow(2.0, depth));
	if ((block_size * 2) > elements.size())
		return;

	typedef typename T::iterator iterator;
	iterator begin = elements.begin();
	iterator end = elements.end();

	size_t total_blocks = elements.size() / block_size;
	for (size_t i = 0; i + 1 < total_blocks; i += 2) {
		iterator left = begin + (i * block_size);
		iterator right = begin + ((i + 1) * block_size);

		comparison_count++;
		if (*left < *right) {
			std::swap_ranges(left, left + block_size, right);
		}
	}

	sort(elements, depth + 1);

	size_t pair_count = elements.size() / (2 * block_size);
	for (size_t i = 0; i < pair_count; ++i) {
		iterator small_start = begin + (i * 2 * block_size + block_size);
		iterator small_end = small_start + block_size;

		std::vector<typename T::value_type> small_block(small_start, small_end);

		iterator left = begin;
		iterator right = small_start;
		while (left < right) {
			iterator mid = left + (((right - left) / block_size) / 2) * block_size;

			comparison_count++;
			if (*mid < small_block[0])
				left = mid + block_size;
			else
				right = mid;
		}
		iterator insert_at = left;

		for (iterator k = small_end - block_size; k >= insert_at + block_size && k >= begin + block_size; k -= block_size)
			std::copy_backward(k - block_size, k, k + block_size);

		std::copy(small_block.begin(), small_block.end(), insert_at);
	}

	size_t remainder_start = pair_count * 2 * block_size;
	size_t remainder_size = elements.size() - remainder_start;

	if (remainder_size >= block_size) {
		iterator rem_start = begin + remainder_start;
		iterator rem_end = rem_start + block_size;

		std::vector<typename T::value_type> rem_block(rem_start, rem_end);

		size_t full_block_count = elements.size() / block_size;
		iterator left = begin;
		iterator right = begin + (full_block_count * block_size);
		while (left < right) {
			iterator mid = left + (((right - left) / block_size) / 2) * block_size;

			comparison_count++;
			if (*mid < rem_block[0])
				left = mid + block_size;
			else
				right = mid;
		}
		iterator insert_at = left;

		for (iterator k = end - block_size; k >= insert_at + block_size && k >= begin + block_size; k -= block_size)
			std::copy_backward(k - block_size, k, k + block_size);

		std::copy(rem_block.begin(), rem_block.end(), insert_at);
	}
}
