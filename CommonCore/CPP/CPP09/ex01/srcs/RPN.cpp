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

void RPN::validateInput(const std::string &input) {
	for (size_t i = 0; i < input.length(); ++i) {
		if (!isdigit(input[i]) && input[i] != ' ' && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/') {
			throw std::invalid_argument("Error: invalid character in input");
		}
	}
}

void RPN::compute(const std::string &input) {
	try {
		RPN::validateInput(input);
	} catch (const std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;
		return;
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
			if (_stack.size() < 2) {
				std::cerr << "Error: not enough operands" << std::endl;
				return;
			}
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
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
					if (b == 0) {
						std::cerr << "Error: division by zero" << std::endl;
						return;
					}
					_stack.push(a / b);
					break;
				default:
					std::cerr << "Error: invalid operator" << std::endl;
					return;
			}
		}
		i++;
	}
	if (_stack.size() != 1) {
		std::cerr << "Error: too many operands" << std::endl;
		return;
	}
	std::cout << _stack.top() << std::endl;
	_stack.pop();
	if (!_stack.empty()) {
		std::cerr << "Error: stack not empty after computation" << std::endl;
		return;
	}
}
