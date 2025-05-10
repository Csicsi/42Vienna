#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		this->_stack = other._stack;
	}
	return *this;
}

bool RPN::isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::validateInput(const std::string &input) {
	for (size_t i = 0; i < input.length(); ++i) {
		if ((isdigit(input[i]) || isOperator(input[i]))
			&& input[i + 1] && input[i + 1] != ' ') {
			throw std::invalid_argument("Error: operand/operator must be separated by a space");
		}
		if (!isdigit(input[i]) && input[i] != ' ' && !isOperator(input[i])) {
			throw std::invalid_argument("Error: invalid character in input");
		}
	}
}

void RPN::compute(const std::string &input) {
	try {
		RPN::validateInput(input);
	} catch (const std::invalid_argument &e) {
		throw;
	}
	size_t i = 0;
	while (input[i] != '\0') {
		if (input[i] == ' ') {
			i++;
			continue;
		}
		if (isdigit(input[i])) {
			_stack.push(input[i] - '0');
		} else {
			if (_stack.size() < 2)
				throw std::invalid_argument("Error: not enough operands");
			double b = _stack.top();
			_stack.pop();
			double a = _stack.top();
			_stack.pop();
			switch (input[i]) {
				case '+':
					_stack.push(a + b);
					break;
				case '-':
					_stack.push(a - b);
					break;
				case '*':
					_stack.push(a * b);
					break;
				case '/':
					if (b == 0)
						throw std::invalid_argument("Error: division by zero");
					_stack.push(a / b);
					break;
				default:
					throw std::invalid_argument("Error: invalid operator");
			}
		}
		i++;
	}
	if (_stack.empty())
		throw std::invalid_argument("Error: no operands");
	if (_stack.size() > 1)
		throw std::invalid_argument("Error: too many operands");
	std::cout << _stack.top() << std::endl;
}
