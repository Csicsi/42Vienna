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
	std::cout << "[createPairs] Block size: " << block_size << "\n";
	for (size_t i = 0; i + 1 < elements.size() / block_size; i += 2) {
		size_t left_index = i * block_size;
		size_t right_index = (i + 1) * block_size;

		std::cout << "  Comparing blocks at " << left_index << " (" << elements[left_index] << ") and " << right_index << " (" << elements[right_index] << ")\n";
		comparison_count++;
		std::cout << "  Comparison count: " << comparison_count << "\n";
		if (elements[left_index] < elements[right_index]) {
			std::cout << "  Swapping blocks\n";
			for (size_t j = 0; j < block_size; ++j)
				std::swap(elements[left_index + j], elements[right_index + j]);
		}
	}
}

template <typename T>
void PmergeMe<T>::merge(const T& elements, size_t block_size, T& bigs, T& smalls) {
	std::cout << "[merge] Block size: " << block_size << "\n";
	size_t pair_count = elements.size() / (2 * block_size);

	for (size_t i = 0; i < pair_count; ++i) {
		size_t left_index = i * 2 * block_size;
		size_t right_index = left_index + block_size;
		std::cout << "  Pair " << i << ": bigs from " << left_index << ", smalls from " << right_index << "\n";
		for (size_t j = 0; j < block_size; ++j)
			bigs.push_back(elements[left_index + j]);
		for (size_t j = 0; j < block_size; ++j)
			smalls.push_back(elements[right_index + j]);
	}
}

template <typename T>
std::vector<size_t> PmergeMe<T>::jacobsthal(size_t pair_count) {
	std::cout << "[jacobsthal] Calculating shifted Jacobsthal sequence\n";
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(1);

	for (size_t n = 2; ; ++n) {
		size_t jn = jacobsthal[n - 1] + 2 * jacobsthal[n - 2];
		if (jn >= pair_count + 1) // allow going slightly beyond for completeness
			break;
		jacobsthal.push_back(jn);
	}

	std::cout << "  Jacobsthal sequence: ";
	for (size_t i = 0; i < jacobsthal.size(); ++i)
		std::cout << jacobsthal[i] << " ";
	std::cout << "\n";

	std::vector<size_t> insertion_order;
	std::vector<char> used(pair_count + 1, 0);  // allow access to pair_count index

	for (size_t i = 2; i < jacobsthal.size(); ++i) { // start at index 2 -> jacobsthal[2] = 3
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

	// Add any remaining numbers not covered
	for (size_t i = pair_count; i > jacobsthal.back(); --i) {
		if (!used[i]) {
			insertion_order.push_back(i);
			used[i] = 1;
		}
	}

	std::cout << "  Shifted Insertion order: ";
	for (size_t i = 0; i < insertion_order.size(); ++i)
		std::cout << insertion_order[i] << " ";
	std::cout << "\n";

	return insertion_order;
}

template <typename T>
void PmergeMe<T>::insertLeftovers(T& bigs, const T& elements, size_t block_size, size_t leftover_start) {
	std::cout << "[insertLeftovers] From index " << leftover_start << "\n";
	size_t leftover_count = container_size - leftover_start;

	if (leftover_count >= block_size) {
		for (size_t i = leftover_start; i + block_size <= container_size; i += block_size) {
			std::cout << "  Inserting leftover block at " << i << "\n";
			size_t left = 0, right = bigs.size() / block_size;
			while (left < right) {
				size_t mid = (left + right) / 2;
				comparison_count++;
				std::cout << "    Comparison " << comparison_count << ": bigs[" << mid * block_size << "] vs elements[" << i << "]\n";
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
		std::cout << "  Appending final leftover elements\n";
		for (size_t i = leftover_start; i < container_size; ++i)
			bigs.push_back(elements[i]);
	}
}

bool isJacobsthal(size_t n) {
    if (n == 0 || n == 1) return true;

    size_t j0 = 0;
    size_t j1 = 1;
    size_t jn = 0;

    while (true) {
        jn = j1 + 2 * j0;
        if (jn == n) return true;
        if (jn > n) return false;

        j0 = j1;
        j1 = jn;
    }
}

template <typename T>
void PmergeMe<T>::binaryInsert(T& bigs, const T& smalls, const T& elements, size_t block_size) {
	std::cout << "[binaryInsert] Inserting smalls into bigs\n";
	std::cout << "Bigs: ";
	for (size_t i = 0; i < bigs.size(); ++i)
		std::cout << bigs[i] << " ";
	std::cout << "\nSmalls: ";
	for (size_t i = 0; i < smalls.size(); ++i)
		std::cout << smalls[i] << " ";
	std::cout << "\n";
	size_t pair_count = container_size / (2 * block_size);
	std::cout << "Pair count: " << pair_count << "\n";
	std::cout << "Insert first, since it is always smaller, than its pair.\n";
	bigs.insert(
		bigs.begin(),
		smalls.begin(),
		smalls.begin() + block_size
	);

	std::vector<size_t> insertion_order = jacobsthal(pair_count);

	size_t prev_j = 1;
	size_t curr_j = 3;

	for (size_t i = 0; i < insertion_order.size(); ++i) {
		size_t idx = insertion_order[i];
		std::cout << "  Inserting index " << idx << "\n";
		size_t small_index = (idx - 1) * block_size;
		size_t right_bound = std::min(bigs.size() / block_size, curr_j + prev_j - 1);
		std::cout << "  Right bound: " << right_bound << std::endl;
		size_t left = 0, right = right_bound;

		std::cout << "  Inserting block starting at smalls[" << small_index << "]\n";

		while (left < right) {
			size_t mid = (left + right) / 2;
			comparison_count++;
			std::cout << "    Comparison " << comparison_count << ": bigs[" << mid * block_size << "] = (" << bigs[mid*block_size] << ") vs smalls[" << small_index << "] = (" << smalls[small_index] << ")\n";
			if (bigs[mid * block_size] < smalls[small_index])
				left = mid + 1;
			else
				right = mid;
		}

		size_t insert_pos = left * block_size;
		std::cout << "Inserting: " << smalls[small_index] << " at position " << insert_pos << "\n";
		bigs.insert(
			bigs.begin() + insert_pos,
			smalls.begin() + small_index,
			smalls.begin() + small_index + block_size
		);

		std::cout << "Bigs after insertion: ";
		for (size_t i = 0; i < bigs.size(); ++i)
			std::cout << bigs[i] << " ";
		std::cout << "\n";

		if (i != 0 && isJacobsthal(insertion_order[i - 1])) {
			size_t next_j = curr_j + 2 * prev_j;
			prev_j = curr_j;
			curr_j = next_j;
		}
	}

	insertLeftovers(bigs, elements, block_size, pair_count * block_size * 2);
}

template <typename T>
void PmergeMe<T>::sort(T &elements, size_t block_size) {
	container_size = elements.size();
	std::cout << "[sort] Block size: " << block_size << ", total elements: " << container_size << "\n";

	if (container_size <= 1) {
		std::cout << "  Already sorted (size <= 1)\n";
		return;
	}

	if ((block_size * 2) > container_size) {
		std::cout << "  Block size too large to continue\n";
		return;
	}

	createPairs(elements, block_size);
	sort(elements, block_size * 2);

	T smalls, bigs;
	merge(elements, block_size, bigs, smalls);

	binaryInsert(bigs, smalls, elements, block_size);

	elements = bigs;

	std::cout << "[sort] Done with block size " << block_size << ", total comparisons: " << comparison_count << "\n";
}
