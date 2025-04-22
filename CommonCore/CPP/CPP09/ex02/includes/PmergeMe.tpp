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
void PmergeMe<T>::createPairs(T &elements, size_t block_size) {
	for (size_t i = 0; i + 1 < elements.size() / block_size; i += 2) {
		size_t left_index = i * block_size;
		size_t right_index = (i + 1) * block_size;

		comparison_count++;
		if (elements[left_index] < elements[right_index]) {
			for (size_t j = 0; j < block_size; ++j)
				std::swap(elements[left_index + j], elements[right_index + j]);
		}
	}
}

template <typename T>
void PmergeMe<T>::merge(const T& elements, size_t block_size, T& bigs, T& smalls) {
	T temp;
	size_t pair_count = elements.size() / (2 * block_size);

	for (size_t i = 0; i < pair_count; ++i) {
		size_t left_index = i * 2 * block_size;
		size_t right_index = left_index + block_size;
		for (size_t j = 0; j < block_size; ++j)
			temp.push_back(elements[left_index + j]);
		for (size_t j = 0; j < block_size; ++j)
			smalls.push_back(elements[right_index + j]);
	}

	for (size_t j = 0; j < block_size; ++j)
		bigs.push_back(smalls[j]);

	for (size_t i = 0; i < temp.size(); ++i)
		bigs.push_back(temp[i]);
}

template <typename T>
std::vector<size_t> PmergeMe<T>::jacobsthal(size_t pair_count, size_t block_size, size_t smalls_size) {
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(1);

	for (size_t n = 2; ; ++n) {
		size_t jn = jacobsthal[n - 1] + 2 * jacobsthal[n - 2];
		if (jn >= smalls_size / block_size)
			break;
		jacobsthal.push_back(jn);
	}

	std::vector<size_t> insertion_order;
	std::vector<bool> used(pair_count, false);
	used[0] = true;

	for (size_t i = 1; i < jacobsthal.size(); ++i) {
		size_t current = jacobsthal[i];
		if (current < pair_count && !used[current]) {
			insertion_order.push_back(current);
			used[current] = true;
		}
		size_t prev = jacobsthal[i - 1];
		for (size_t j = current - 1; j > prev; --j) {
			if (j < pair_count && !used[j]) {
				insertion_order.push_back(j);
				used[j] = true;
			}
		}
	}

	for (size_t i = pair_count - 1; i > jacobsthal.back(); --i) {
		if (!used[i]) {
			insertion_order.push_back(i);
			used[i] = true;
		}
	}

	return insertion_order;
}

template <typename T>
void PmergeMe<T>::insertLeftovers(T& bigs, const T& elements, size_t block_size, size_t leftover_start) {
	size_t leftover_count = container_size - leftover_start;

	if (leftover_count >= block_size) {
		for (size_t i = leftover_start; i + block_size <= container_size; i += block_size) {
			size_t left = 0, right = bigs.size() / block_size;
			while (left < right) {
				size_t mid = (left + right) / 2;
				comparison_count++;
				if (bigs[mid * block_size] < elements[i])
					left = mid + 1;
				else
					right = mid;
			}

			size_t insert_pos = left * block_size;
			bigs.insert(bigs.begin() + insert_pos,
				elements.begin() + i,
				elements.begin() + i + block_size);
		}
		leftover_start += (leftover_count / block_size) * block_size;
	}

	if (leftover_start < container_size) {
		for (size_t i = leftover_start; i < container_size; ++i)
			bigs.push_back(elements[i]);
	}
}

template <typename T>
void PmergeMe<T>::binaryInsert(T& bigs, const T& smalls, const T& elements, size_t block_size) {
	size_t pair_count = container_size / (2 * block_size);
	std::vector<size_t> insertion_order = jacobsthal(pair_count, block_size, smalls.size());

	for (size_t i = 0; i < insertion_order.size(); ++i) {
		size_t idx = insertion_order[i];
		size_t small_index = idx * block_size;

		size_t left = 0, right = bigs.size() / block_size;
		while (left < right) {
			size_t mid = (left + right) / 2;
			comparison_count++;
			if (bigs[mid * block_size] < smalls[small_index])
				left = mid + 1;
			else
				right = mid;
		}

		size_t insert_pos = left * block_size;
		bigs.insert(bigs.begin() + insert_pos,
			smalls.begin() + small_index,
			smalls.begin() + small_index + block_size);
	}

	insertLeftovers(bigs, elements, block_size, pair_count * block_size * 2);
}


template <typename T>
void PmergeMe<T>::sort(T &elements, size_t block_size) {

	container_size = elements.size();

	if (container_size <= 1)
		return;

	if ((block_size * 2) > container_size)
		return;

	createPairs(elements, block_size);

	sort(elements, block_size * 2);

	T smalls, bigs;
	merge(elements, block_size, bigs, smalls);

	binaryInsert(bigs, smalls, elements, block_size);

	elements = bigs;
}
