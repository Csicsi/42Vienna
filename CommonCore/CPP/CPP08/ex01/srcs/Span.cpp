#include "Span.hpp"

Span::Span() : _max(0) {}

Span::Span(unsigned int N) : _max(N) {}

Span::~Span() {}

Span::Span(const Span &other) {
	*this = other;
}

Span &Span::operator=(const Span &other) {
	_max = other._max;
	_nums = other._nums;
	return *this;
}

void Span::addNumber(int number) {
	if (_nums.size() >= _max)
		throw std::runtime_error("Span is full");
	_nums.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_nums.size() + std::distance(begin, end) > _max)
		throw std::runtime_error("Span is full");
	_nums.insert(_nums.end(), begin, end);
}

int Span::shortestSpan() const {
	if (_nums.size() < 2)
		throw std::runtime_error("Span is too short");
	std::vector<int> sorted(_nums);
	std::sort(sorted.begin(), sorted.end());
	int min = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++) {
		int diff = sorted[i] - sorted[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan() const {
	if (_nums.size() < 2)
		throw std::runtime_error("Span is too short");
	std::vector<int> sorted(_nums);
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}
