#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
	unsigned int _max;
	std::vector<int> _nums;
	Span();

public:
	Span(unsigned int N);
	~Span();
	Span(const Span &other);
	Span &operator=(const Span &other);

	void addNumber(int number);
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	int shortestSpan() const;
	int longestSpan() const;
};

#endif
