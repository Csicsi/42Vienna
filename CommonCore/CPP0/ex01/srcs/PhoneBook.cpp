#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(): index(0) {}

bool PhoneBook::getInput(const std::string &prompt, std::string &input) const {
	std::cout << prompt;
	if (!std::getline(std::cin, input)) {
		std::cin.clear();
		std::cin.ignore(0, '\n');
		std::freopen("/dev/tty", "r", stdin);
		std::cout << "\nInput interrupted. Operation aborted.\n";
		return false;
	}
	if (input == "") {
		std::cout << "Must not be empty!" << std::endl;
		getInput(prompt, input);
	}
	return true;
}

bool PhoneBook::getValidatedPhoneNumber(const std::string &prompt, std::string &phoneNumber) const {
	if (!getInput(prompt, phoneNumber))
		return false;

	bool	isValid = true;
	size_t	i = 0;

	if (phoneNumber[0] == '+')
		i++;
	for (; i < phoneNumber.length(); i++) {
		if (!isdigit(phoneNumber[i])) {
			isValid = false;
			break;
		}
	}
	if (isValid && !phoneNumber.empty())
		return true;
	std::cout << "Invalid phone number!"
		<< " Please enter a valid phone number" << std::endl;
	getValidatedPhoneNumber(prompt, phoneNumber);
	return true;
}

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
		std::cout << "All fields must be filled!\n";
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
		std::cout << "Invalid index!\n";
		return;
	}

	std::cout << "First Name: " << contacts[index].getFirstName() << "\n"
			  << "Last Name: " << contacts[index].getLastName() << "\n"
			  << "Nickname: " << contacts[index].getNickname() << "\n"
			  << "Phone Number: " << contacts[index].getPhoneNumber() << "\n"
			  << "Darkest Secret: " << contacts[index].getDarkestSecret() << "\n";
}

size_t PhoneBook::ft_strlen(const std::string& str) const {
	size_t charCount = 0;
	for (size_t i = 0; i < str.length();) {
		if ((str[i] & 0x80) == 0)
			i += 1;
		else if ((str[i] & 0xE0) == 0xC0)
			i += 2;
		else if ((str[i] & 0xF0) == 0xE0)
			i += 3;
		else if ((str[i] & 0xF8) == 0xF0)
			i += 4;
		charCount++;
	}
	return charCount;
}

std::string PhoneBook::turncate(std::string src) const {
	std::ostringstream dest;
	size_t charCount = ft_strlen(src);

	if (charCount < 10) {
		size_t padCount = 10 - charCount;
		dest << std::string(padCount, ' ') << src;
		src = dest.str();
	} else if (charCount > 10) {
		size_t charCounter = 0;
		size_t byteIndex = 0;

		while (charCounter < 9 && byteIndex < src.length()) {
			if ((src[byteIndex] & 0x80) == 0)
				byteIndex += 1;
			else if ((src[byteIndex] & 0xE0) == 0xC0)
				byteIndex += 2;
			else if ((src[byteIndex] & 0xF0) == 0xE0)
				byteIndex += 3;
			else if ((src[byteIndex] & 0xF8) == 0xF0)
				byteIndex += 4;
			charCounter++;
		}
		src = src.substr(0, byteIndex) + ".";
	}
	return src;
}

void PhoneBook::displayContact(const Contact &contact, int index) const {
	std::cout << std::setw(10) << index << "|"
		<< turncate(contact.getFirstName()) << "|"
		<< turncate(contact.getLastName()) << "|"
		<< turncate(contact.getNickname()) << "|"
		<< std::endl;
}
