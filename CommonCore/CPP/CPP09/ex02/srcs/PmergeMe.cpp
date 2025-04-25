#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : comparison_count(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) : comparison_count(other.comparison_count) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other)
		this->comparison_count = other.comparison_count;
	return *this;
}

PmergeMe::~PmergeMe() {}

int PmergeMe::getComparisonCount() const {
	return comparison_count;
}

void PmergeMe::setComparisonCount(int count) {
	comparison_count = count;
}

bool PmergeMe::isJacobsthal(size_t n) const {
	if (n == 0 || n == 1)
		return true;
	size_t j0 = 0, j1 = 1, jn = 0;
	while (true) {
		jn = j1 + 2 * j0;
		if (jn == n)
			return true;
		if (jn > n)
			return false;
		j0 = j1;
		j1 = jn;
	}
}

void PmergeMe::sortVector(std::vector<int> &elements, size_t block_size) {
	size_t container_size = elements.size();

	if (container_size <= 1 || block_size * 2 > container_size)
		return;

	createPairsVector(elements, block_size);
	sortVector(elements, block_size * 2);

	std::vector<int> bigs, smalls;
	mergeVector(elements, block_size, bigs, smalls);
	binaryInsertVector(bigs, smalls, block_size);

	if (bigs.size() < container_size)
		bigs.insert(bigs.end(), elements.begin() + bigs.size(), elements.end());

	elements = bigs;
}

void PmergeMe::createPairsVector(std::vector<int> &elements, size_t block_size) {
	for (size_t i = 0; i + 1 < elements.size() / block_size; i += 2) {
		std::vector<int>::iterator left = elements.begin() + (i * block_size);
		std::vector<int>::iterator right = elements.begin() + ((i + 1) * block_size);

		comparison_count++;
		if (*left < *right) {
			for (size_t j = 0; j < block_size; ++j)
				std::iter_swap(left + j, right + j);
		}
	}
}

void PmergeMe::mergeVector(const std::vector<int> &elements, size_t block_size, std::vector<int> &bigs, std::vector<int> &smalls) {
	size_t pair_count = elements.size() / (2 * block_size);

	for (size_t i = 0; i < pair_count; ++i) {
		std::vector<int>::const_iterator left = elements.begin() + (i * 2 * block_size);
		std::vector<int>::const_iterator right = left + block_size;

		bigs.insert(bigs.end(), left, left + block_size);
		smalls.insert(smalls.end(), right, right + block_size);
	}

	std::vector<int>::const_iterator leftover = elements.begin() + (pair_count * 2 * block_size);
	if (elements.end() - leftover >= static_cast<ptrdiff_t>(block_size))
		smalls.insert(smalls.end(), leftover, leftover + block_size);
}

std::vector<size_t> PmergeMe::jacobsthalVector(size_t pair_count) const {
	std::vector<size_t> jacob;
	jacob.push_back(1);
	jacob.push_back(1);

	for (size_t n = 2;; ++n) {
		size_t jn = jacob[n - 1] + 2 * jacob[n - 2];
		if (jn >= pair_count + 1)
			break;
		jacob.push_back(jn);
	}

	std::vector<size_t> insertion_order;
	std::vector<char> used(pair_count + 1, 0);

	for (size_t i = 2; i < jacob.size(); ++i) {
		size_t current = jacob[i];
		if (current <= pair_count && !used[current]) {
			insertion_order.push_back(current);
			used[current] = 1;
		}
		size_t prev = jacob[i - 1];
		for (size_t j = current - 1; j > prev; --j) {
			if (j <= pair_count && !used[j]) {
				insertion_order.push_back(j);
				used[j] = 1;
			}
		}
	}

	for (size_t i = pair_count; i > jacob.back(); --i) {
		if (!used[i]) {
			insertion_order.push_back(i);
			used[i] = 1;
		}
	}

	return insertion_order;
}

void PmergeMe::binaryInsertVector(std::vector<int> &bigs, const std::vector<int> &smalls, size_t block_size) {
	size_t pair_count = smalls.size() / block_size;

	bigs.insert(bigs.begin(), smalls.begin(), smalls.begin() + block_size);

	std::vector<size_t> insertion_order = jacobsthalVector(pair_count);
	size_t prev_j = 1, curr_j = 3;

	for (size_t i = 0; i < insertion_order.size(); ++i) {
		size_t idx = insertion_order[i];
		std::vector<int>::const_iterator small_block = smalls.begin() + (idx - 1) * block_size;

		size_t right_bound = std::min(bigs.size() / block_size, curr_j + prev_j - 1);
		size_t left = 0, right = right_bound;

		while (left < right) {
			size_t mid = (left + right) / 2;
			comparison_count++;
			std::vector<int>::iterator mid_block = bigs.begin() + mid * block_size;
			if (*mid_block < *small_block)
				left = mid + 1;
			else
				right = mid;
		}

		bigs.insert(bigs.begin() + left * block_size, small_block, small_block + block_size);

		if (i != 0 && isJacobsthal(i + 2)) {
			size_t next_j = curr_j + 2 * prev_j;
			prev_j = curr_j;
			curr_j = next_j;
		}
	}
}

void PmergeMe::sortDeque(std::deque<int> &elements, size_t block_size) {
	size_t container_size = elements.size();

	if (container_size <= 1 || block_size * 2 > container_size)
		return;

	createPairsDeque(elements, block_size);
	sortDeque(elements, block_size * 2);

	std::deque<int> bigs, smalls;
	mergeDeque(elements, block_size, bigs, smalls);
	binaryInsertDeque(bigs, smalls, block_size);

	if (bigs.size() < container_size)
		bigs.insert(bigs.end(), elements.begin() + bigs.size(), elements.end());

	elements = bigs;
}

void PmergeMe::createPairsDeque(std::deque<int> &elements, size_t block_size) {
	for (size_t i = 0; i + 1 < elements.size() / block_size; i += 2) {
		std::deque<int>::iterator left = elements.begin() + (i * block_size);
		std::deque<int>::iterator right = elements.begin() + ((i + 1) * block_size);

		comparison_count++;
		if (*left < *right) {
			for (size_t j = 0; j < block_size; ++j)
				std::iter_swap(left + j, right + j);
		}
	}
}

void PmergeMe::mergeDeque(const std::deque<int> &elements, size_t block_size, std::deque<int> &bigs, std::deque<int> &smalls) {
	size_t pair_count = elements.size() / (2 * block_size);

	for (size_t i = 0; i < pair_count; ++i) {
		std::deque<int>::const_iterator left = elements.begin() + (i * 2 * block_size);
		std::deque<int>::const_iterator right = left + block_size;

		bigs.insert(bigs.end(), left, left + block_size);
		smalls.insert(smalls.end(), right, right + block_size);
	}

	std::deque<int>::const_iterator leftover = elements.begin() + (pair_count * 2 * block_size);
	if (elements.end() - leftover >= static_cast<ptrdiff_t>(block_size))
		smalls.insert(smalls.end(), leftover, leftover + block_size);
}

std::deque<size_t> PmergeMe::jacobsthalDeque(size_t pair_count) const {
	std::deque<size_t> jacob;
	jacob.push_back(1);
	jacob.push_back(1);

	for (size_t n = 2;; ++n) {
		size_t jn = jacob[n - 1] + 2 * jacob[n - 2];
		if (jn >= pair_count + 1)
			break;
		jacob.push_back(jn);
	}

	std::deque<size_t> insertion_order;
	std::vector<char> used(pair_count + 1, 0);

	for (size_t i = 2; i < jacob.size(); ++i) {
		size_t current = jacob[i];
		if (current <= pair_count && !used[current]) {
			insertion_order.push_back(current);
			used[current] = 1;
		}
		size_t prev = jacob[i - 1];
		for (size_t j = current - 1; j > prev; --j) {
			if (j <= pair_count && !used[j]) {
				insertion_order.push_back(j);
				used[j] = 1;
			}
		}
	}

	for (size_t i = pair_count; i > jacob.back(); --i) {
		if (!used[i]) {
			insertion_order.push_back(i);
			used[i] = 1;
		}
	}

	return insertion_order;
}

void PmergeMe::binaryInsertDeque(std::deque<int> &bigs, const std::deque<int> &smalls, size_t block_size) {
	size_t pair_count = smalls.size() / block_size;

	bigs.insert(bigs.begin(), smalls.begin(), smalls.begin() + block_size);

	std::deque<size_t> insertion_order = jacobsthalDeque(pair_count);
	size_t prev_j = 1, curr_j = 3;

	for (size_t i = 0; i < insertion_order.size(); ++i) {
		size_t idx = insertion_order[i];
		std::deque<int>::const_iterator small_block = smalls.begin() + (idx - 1) * block_size;

		size_t right_bound = std::min(bigs.size() / block_size, curr_j + prev_j - 1);
		size_t left = 0, right = right_bound;

		while (left < right) {
			size_t mid = (left + right) / 2;
			comparison_count++;
			std::deque<int>::iterator mid_block = bigs.begin() + mid * block_size;
			if (*mid_block < *small_block)
				left = mid + 1;
			else
				right = mid;
		}

		bigs.insert(bigs.begin() + left * block_size, small_block, small_block + block_size);

		if (i != 0 && isJacobsthal(i + 2)) {
			size_t next_j = curr_j + 2 * prev_j;
			prev_j = curr_j;
			curr_j = next_j;
		}
	}
}
