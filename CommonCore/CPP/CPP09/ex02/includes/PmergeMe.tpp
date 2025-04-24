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
#if DEBUG
	std::cout << "[createPairs] Block size: " << block_size << "\n";
#endif
	for (size_t i = 0; i + 1 < elements.size() / block_size; i += 2) {
		size_t left_index = i * block_size;
		size_t right_index = (i + 1) * block_size;

#if DEBUG
		std::cout << "  Comparing blocks at " << left_index << " (" << elements[left_index]
		          << ") and " << right_index << " (" << elements[right_index] << ")\n";
#endif
		comparison_count++;
#if DEBUG
		std::cout << "  Comparison count: " << comparison_count << "\n";
#endif
		if (elements[left_index] < elements[right_index]) {
#if DEBUG
			std::cout << "  Swapping blocks\n";
#endif
			for (size_t j = 0; j < block_size; ++j)
				std::swap(elements[left_index + j], elements[right_index + j]);
		}
	}
}

template <typename T>
void PmergeMe<T>::merge(const T& elements, size_t block_size, T& bigs, T& smalls) {
#if DEBUG
	std::cout << "[merge] Block size: " << block_size << "\n";
#endif
	size_t pair_count = elements.size() / (2 * block_size);

	for (size_t i = 0; i < pair_count; ++i) {
		size_t left_index = i * 2 * block_size;
		size_t right_index = left_index + block_size;
#if DEBUG
		std::cout << "  Pair " << i << ": bigs from " << left_index << ", smalls from " << right_index << "\n";
#endif
		for (size_t j = 0; j < block_size; ++j)
			bigs.push_back(elements[left_index + j]);
		for (size_t j = 0; j < block_size; ++j)
			smalls.push_back(elements[right_index + j]);
	}
}

template <typename T>
std::vector<size_t> PmergeMe<T>::jacobsthal(size_t pair_count) {
#if DEBUG
	std::cout << "[jacobsthal] Calculating shifted Jacobsthal sequence\n";
#endif
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(1);

	for (size_t n = 2; ; ++n) {
		size_t jn = jacobsthal[n - 1] + 2 * jacobsthal[n - 2];
		if (jn >= pair_count + 1)
			break;
		jacobsthal.push_back(jn);
	}

#if DEBUG
	std::cout << "  Jacobsthal sequence: ";
	for (size_t i = 0; i < jacobsthal.size(); ++i)
		std::cout << jacobsthal[i] << " ";
	std::cout << "\n";
#endif

	std::vector<size_t> insertion_order;
	std::vector<char> used(pair_count + 1, 0);

	for (size_t i = 2; i < jacobsthal.size(); ++i) {
		size_t current = jacobsthal[i];
		if (current <= pair_count && !used[current]) {
			insertion_order.push_back(current);
			used[current] = 1;
		}
		size_t prev = jacobsthal[i - 1];
		for (size_t j = current - 1; j > prev; --j) {
			if (j <= pair_count && !used[j]) {
				insertion_order.push_back(j);
				used[j] = 1;
			}
		}
	}

	for (size_t i = pair_count; i > jacobsthal.back(); --i) {
		if (!used[i]) {
			insertion_order.push_back(i);
			used[i] = 1;
		}
	}

#if DEBUG
	std::cout << "  Shifted Insertion order: ";
	for (size_t i = 0; i < insertion_order.size(); ++i)
		std::cout << insertion_order[i] << " ";
	std::cout << "\n";
#endif

	return insertion_order;
}

bool isJacobsthal(size_t n) {
	if (n == 0 || n == 1) return true;
	size_t j0 = 0, j1 = 1, jn = 0;
	while (true) {
		jn = j1 + 2 * j0;
		if (jn == n) return true;
		if (jn > n) return false;
		j0 = j1;
		j1 = jn;
	}
}

template <typename T>
size_t PmergeMe<T>::insertLeftovers(T& bigs, const T& elements, size_t block_size, size_t leftover_start) {
	size_t leftover_size = container_size - leftover_start;
	if (leftover_size < block_size)
		return -1;

#if DEBUG
	std::cout << "[insertLeftovers] Inserting leftover block from index " << leftover_start << "\n";
#endif

	size_t left = 0, right = bigs.size() / block_size;
	while (left < right) {
		size_t mid = (left + right) / 2;
		comparison_count++;
#if DEBUG
		std::cout << "  Binary search mid: " << mid * block_size << ", value: " << bigs[mid * block_size] << "\n";
#endif
		if (bigs[mid * block_size] < elements[leftover_start])
			left = mid + 1;
		else
			right = mid;
	}

	size_t insert_pos = left * block_size;
#if DEBUG
	std::cout << "  Inserting leftover at position: " << insert_pos << "\n";
#endif
	bigs.insert(
		bigs.begin() + insert_pos,
		elements.begin() + leftover_start,
		elements.begin() + leftover_start + block_size
	);

	return (insert_pos);
}

template <typename T>
void PmergeMe<T>::binaryInsert(T& bigs, const T& smalls, const T& elements, size_t block_size) {
	size_t pair_count = container_size / (2 * block_size);
#if DEBUG
	std::cout << "[binaryInsert] Inserting first small block at beginning\n";
#endif
	bigs.insert(
		bigs.begin(),
		smalls.begin(),
		smalls.begin() + block_size
	);

	size_t leftover_block_index = insertLeftovers(
		bigs,
		elements,
		block_size,
		pair_count * 2 * block_size
	);

	std::vector<size_t> insertion_order = jacobsthal(pair_count);
	size_t prev_j = 1, curr_j = 3;

	for (size_t i = 0; i < insertion_order.size(); ++i) {
		size_t idx = insertion_order[i];
		size_t small_index = (idx - 1) * block_size;

#if DEBUG
		std::cout << "  Inserting small block " << idx << " from index " << small_index << "\n";
#endif

		size_t right = std::min(bigs.size() / block_size, curr_j + prev_j);
		//if (small_index < leftover_block_index || leftover_block_index <= 0)
		//	--right;

		size_t left = 0;

		if (leftover_block_index >= 0 && small_index >= static_cast<size_t>(leftover_block_index))
			right = std::min(bigs.size() / block_size, right + 1);

		while (left < right) {
			size_t mid = (left + right) / 2;
			comparison_count++;
#if DEBUG
			std::cout << "    Binary search mid: " << mid * block_size << ", value: " << bigs[mid * block_size] << "\n";
#endif
			if (bigs[mid * block_size] < smalls[small_index])
				left = mid + 1;
			else
				right = mid;
		}

		size_t insert_pos = left * block_size;
#if DEBUG
		std::cout << "  Inserting at position: " << insert_pos << "\n";
#endif
		bigs.insert(
			bigs.begin() + insert_pos,
			smalls.begin() + small_index,
			smalls.begin() + small_index + block_size
		);

		if (i != 0 && isJacobsthal(insertion_order[i - 1])) {
			size_t next_j = curr_j + 2 * prev_j;
			prev_j = curr_j;
			curr_j = next_j;
#if DEBUG
			std::cout << "  Updated Jacobsthal bounds: prev=" << prev_j << ", curr=" << curr_j << "\n";
#endif
		}
	}
}

template <typename T>
void PmergeMe<T>::sort(T &elements, size_t block_size) {
	container_size = elements.size();
#if DEBUG
	std::cout << "[sort] Block size: " << block_size << ", total elements: " << container_size << "\n";
#endif

	if (container_size <= 1) {
#if DEBUG
		std::cout << "  Already sorted (size <= 1)\n";
#endif
		return;
	}

	if ((block_size * 2) > container_size) {
#if DEBUG
		std::cout << "  Block size too large to continue\n";
#endif
		return;
	}

	createPairs(elements, block_size);
	sort(elements, block_size * 2);

	T smalls, bigs;
	merge(elements, block_size, bigs, smalls);
	binaryInsert(bigs, smalls, elements, block_size);

	elements = bigs;
#if DEBUG
	std::cout << "[sort] Done with block size " << block_size << ", total comparisons: " << comparison_count << "\n";
#endif
}
