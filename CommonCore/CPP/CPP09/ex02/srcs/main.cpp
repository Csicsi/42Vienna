#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

int g_comparison_count = 0;

struct Element {
	int value;
	const Element* origin1;
	const Element* origin2;

	Element(int val, const Element* o1 = NULL, const Element* o2 = NULL)
		: value(val), origin1(o1), origin2(o2) {}
};

void printVector(const std::vector<Element>& vec, const std::string& label) {
	std::cout << label << ": ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i].value << " ";
	std::cout << std::endl;
}

void binaryInsert(std::vector<Element>& sorted, const Element& elem) {
	size_t left = 0;
	size_t right = sorted.size();

	std::cout << "  [Insert] Inserting " << elem.value << "...\n";

	while (left < right) {
		size_t mid = left + (right - left) / 2;

		std::cout << "    Compare " << elem.value << " vs " << sorted[mid].value << " at " << mid << "\n";
		++g_comparison_count;

		if (elem.value < sorted[mid].value) {
			std::cout << "    → go left\n";
			right = mid;
		} else {
			std::cout << "    → go right\n";
			left = mid + 1;
		}
	}
	std::cout << "  → Insert at " << left << "\n\n";
	sorted.insert(sorted.begin() + left, elem);
}

std::vector<size_t> getJacobsthalInsertionOrder(size_t n) {
	std::vector<size_t> order;
	std::vector<size_t> jacob;

	jacob.push_back(1);
	jacob.push_back(3);
	while (true) {
		size_t next = jacob[jacob.size() - 1] * 2 + jacob[jacob.size() - 2];
		if (next >= n)
			break;
		jacob.push_back(next);
	}

	std::vector<bool> inserted(n, false);
	for (int i = jacob.size() - 1; i >= 0; --i) {
		for (size_t j = jacob[i]; j > (i == 0 ? 0 : jacob[i - 1]); --j) {
			if (j - 1 < n && !inserted[j - 1]) {
				order.push_back(j - 1);
				inserted[j - 1] = true;
			}
		}
	}
	if (n > 0 && !inserted[0])
		order.push_back(0);

	return order;
}

int getTheoreticalMaxComparisons(int n) {
	static const int maxComp[] = {
		0, 1, 3, 5, 7, 10, 13, 16, 19, 22,
		26, 30, 34, 38, 42, 46, 50, 54, 58, 62,
		66, 71, 76, 81, 86, 91, 96, 101, 106, 111,
		116, 121, 126, 131
	};
	if (n < 0)
		return 0;
	if (n <= 33)
		return maxComp[n];
	return static_cast<int>(n * std::log(n) / std::log(2) - 1.443 * n);
}

void mergeInsertSort(std::vector<Element>& elements, int depth = 0) {
	if (elements.size() <= 1)
		return;

	std::string indent(depth * 2, ' ');
	std::cout << indent << "[Sort] Depth " << depth << " — " << elements.size() << " elements\n";

	std::vector<Element> bigs;
	std::vector<Element> smalls;

	for (size_t i = 0; i + 1 < elements.size(); i += 2) {
		const Element& a = elements[i];
		const Element& b = elements[i + 1];

		++g_comparison_count;

		if (a.value > b.value) {
			std::cout << indent << "  [Pair] (" << a.value << ", " << b.value << ") → big: " << a.value << "\n";
			bigs.push_back(Element(a.value, &a, &b));
			smalls.push_back(b);
		} else {
			std::cout << indent << "  [Pair] (" << a.value << ", " << b.value << ") → big: " << b.value << "\n";
			bigs.push_back(Element(b.value, &a, &b));
			smalls.push_back(a);
		}
	}
	if (elements.size() % 2 != 0) {
		std::cout << indent << "  [Unpaired] " << elements.back().value << " → smalls\n";
		smalls.push_back(elements.back());
	}

	mergeInsertSort(bigs, depth + 1);

	std::vector<Element> result = bigs;

	std::vector<size_t> order = getJacobsthalInsertionOrder(smalls.size());

	std::vector<bool> seen(smalls.size(), false);
	std::vector<size_t> full_order;
	for (size_t i = 0; i < order.size(); ++i) {
		if (order[i] < smalls.size() && !seen[order[i]]) {
			full_order.push_back(order[i]);
			seen[order[i]] = true;
		}
	}
	for (size_t i = 0; i < smalls.size(); ++i) {
		if (!seen[i])
			full_order.push_back(i);
	}

	if (!full_order.empty()) {
		const Element& first = smalls[full_order[0]];
		std::cout << indent << "  [Insert Step] FIRST (no compare): " << first.value << "\n";
		result.insert(result.begin(), first);
	}

	for (size_t i = 1; i < full_order.size(); ++i) {
		const Element& elem = smalls[full_order[i]];
		std::cout << indent << "  [Insert Step] small[" << full_order[i] << "] = " << elem.value << "\n";
		binaryInsert(result, elem);
	}

	elements = result;

	std::cout << indent << "[Sorted] Depth " << depth << ": ";
	for (size_t i = 0; i < elements.size(); ++i)
		std::cout << elements[i].value << " ";
	std::cout << "\n\n";
}

int main() {
	srand(static_cast<unsigned>(time(0)));
	const size_t len = 10;
	int raw[len];
	for (size_t i = 0; i < len; ++i) {
		raw[i] = rand() % 100;
	}

	std::cout << "[Start] Input: ";
	for (size_t i = 0; i < len; ++i)
		std::cout << raw[i] << " ";
	std::cout << "\n\n";

	std::vector<Element> elements;
	for (size_t i = 0; i < len; ++i)
		elements.push_back(Element(raw[i]));

	mergeInsertSort(elements);

	std::cout << "[Done] Sorted: ";
	for (size_t i = 0; i < elements.size(); ++i)
		std::cout << elements[i].value << " ";
	std::cout << "\n";

	std::cout << "\n[Stats] Actual comparisons:     " << g_comparison_count << "\n";
	std::cout << "[Stats] Theoretical max (F(" << len << ")): " << getTheoreticalMaxComparisons(static_cast<int>(len)) << "\n";

	return 0;
}
