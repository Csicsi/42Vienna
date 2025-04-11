#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <list>
#include <sstream>

class RPN
{
private:
	std::stack<int, std::list<int> > _stack;

	void validateInput(const std::string &input);
public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);

	void compute(const std::string &input);
};

#endif
