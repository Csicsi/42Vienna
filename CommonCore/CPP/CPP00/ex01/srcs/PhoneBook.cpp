#include "../includes/PhoneBook.hpp"
#include "../includes/Utils.hpp"

PhoneBook::PhoneBook(): index(0) {}

void PhoneBook::addContact() {
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	if (!getInput("Enter First Name: ", firstName) ||
		!getInput("Enter Last Name: ", lastName) ||
		!getInput("Enter Nickname: ", nickname) ||
		!getValidatedPhoneNumber("Enter Phone Number: ", phoneNumber) ||
		!getInput("Enter Your Darkest Secret: ", darkestSecret)) {
		return;
	}

	if (firstName.empty() || lastName.empty() || nickname.empty() ||
		phoneNumber.empty() || darkestSecret.empty()) {
		std::cerr << "All fields must be filled!\n";
		return;
	}

	contacts[index] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	index = (index + 1) % 8;
}

bool PhoneBook::isValidIndex(const std::string &input, int &index) const {
	for (size_t i = 0; i < input.length(); ++i) {
		if (!std::isdigit(input[i])) {
			return false;
		}
	}

	std::istringstream iss(input);
	if (!(iss >> index)) {
		return false;
	}

	if (index < 0 || index >= 8 || contacts[index].isEmpty()) {
		return false;
	}

	return true;
}

void PhoneBook::searchContacts() const {
	int			index;
	std::string	input;

	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "\n";
	std::cout << "-------------------------------------------\n";

	for (int i = 0; i < 8; ++i) {
		if (!contacts[i].isEmpty())
			displayContact(contacts[i], i);
	}

	if (!getInput("Enter index to view details: ", input)
		|| input.empty() || !isValidIndex(input, index)) {
		std::cerr << "Invalid index!\n";
		return;
	}

	std::cout << "First Name: " << contacts[index].getFirstName() << "\n"
			  << "Last Name: " << contacts[index].getLastName() << "\n"
			  << "Nickname: " << contacts[index].getNickname() << "\n"
			  << "Phone Number: " << contacts[index].getPhoneNumber() << "\n"
			  << "Darkest Secret: " << contacts[index].getDarkestSecret() << "\n";
}

void PhoneBook::displayContact(const Contact &contact, int index) const {
	std::cout << std::setw(10) << index << "|"
		<< turncate(contact.getFirstName()) << "|"
		<< turncate(contact.getLastName()) << "|"
		<< turncate(contact.getNickname()) << "|"
		<< std::endl;
}
