#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
private:
	typedef void (Harl::*complaintPtr)();
	void debug();
	void info();
	void warning();
	void error();
public:
	Harl();
	~Harl();

	void complain(std::string level);
};

#endif // HARL_HPP
