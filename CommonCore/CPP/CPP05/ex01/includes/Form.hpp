#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Form {
private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _execGrade;
public:
	Form();
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
};

#endif
