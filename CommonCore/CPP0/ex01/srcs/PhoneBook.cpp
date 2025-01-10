#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(): index(0) {}

void PhoneBook::addContact() {
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter Your Darkest Secret: ";
	std::getline(std::cin, darkestSecret);

	if (firstName.empty() || lastName.empty() || nickname.empty()
		|| phoneNumber.empty() || darkestSecret.empty()) {
		std::cout << "All fields must be filled!" << std::endl;
		return;
	}
	contacts[index] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	index = (index + 1) % 8;
}

void PhoneBook::searchContacts() const {
	int index;

	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << "\n";
	std::cout << "-------------------------------------------" << std::endl;

	for (int i = 0; i < 8; i++) {
		if (!contacts[i].isEmpty())
			displayContact(contacts[i], i);
	}

	std::cout << "Enter index to view details: ";
	std::cin >> index;
	std::cin.ignore();
	if (index < 0 || index >= 8 || contacts[index].isEmpty()) {
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::displayContact(const Contact &contact, int index) const {
	std::cout << std::setw(10) << index << "|"
		<< std::setw(10) << (contact.getFirstName().length() > 10
		? contact.getFirstName().substr(0, 9) + "." : contact.getFirstName()) << "|"
		<< std::setw(10) << (contact.getLastName().length() > 10
		? contact.getLastName().substr(0, 9) + "." : contact.getLastName()) << "|"
		<< std::setw(10) << (contact.getNickname().length() > 10
		? contact.getNickname().substr(0, 9) + "." : contact.getNickname()) << "|"
		<< std::endl;
}
