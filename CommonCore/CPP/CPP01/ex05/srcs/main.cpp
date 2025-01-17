#include "../includes/Harl.hpp"

int main() {
	Harl harl;

	harl.complain("DEBUG");
	std::cout << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	harl.complain("INVALID");
	std::cout << std::endl;
	harl.complain("debug");
	std::cout << std::endl;
	harl.complain("info");
	std::cout << std::endl;
	harl.complain("warning");
	std::cout << std::endl;
	harl.complain("error");
	std::cout << std::endl;

	/*harl.debug();
	harl.warning();
	harl.info();
	harl.error();*/

	return 0;
}
