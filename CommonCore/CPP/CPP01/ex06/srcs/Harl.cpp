#include "../includes/Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::debug() {
	std::cout << "*Debug*: I love having extra bacon for my 7XL-double-cheese"
		<< "-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "*Info*: I cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t "
		<< "be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "*Warning*: I think I deserve to have some extra bacon for free."
		<< " I’ve been coming for years whereas you started working here since "
		<< "last month." << std::endl;
}

void Harl::error() {
	std::cerr << "*Error*: This is unacceptable! I want to speak to the manager "
		<< "now." << std::endl;
}

void Harl::complain(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	for (i = 0; i < 4 && levels[i] != level; i++) {}
	switch (i) {
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
				<< std::endl;
	}
}
