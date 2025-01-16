#include "PhoneBook.hpp"

int main() {
	PhoneBook	phoneBook;
	std::string	command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command)) {
			std::cin.clear();
			std::cin.ignore(0, '\n');
			std::freopen("/dev/tty", "r", stdin);
			std::cout << "\n";
			continue;
		}
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContacts();
		else if (command == "EXIT")
			break;
		else
			std::cerr << "Invalid command!" << std::endl;
	}
	return 0;
}
