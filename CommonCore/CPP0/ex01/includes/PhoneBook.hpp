#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>

class PhoneBook {
private:
	Contact contacts[8];
	int		index;

	void		displayContact(const Contact &contact, int index) const;

public:
	PhoneBook();
	void addContact();
	void searchContacts() const;
	bool getInput(const std::string &prompt, std::string &input) const;
	bool getValidatedPhoneNumber(const std::string &prompt,
		std::string &phoneNumber) const;
	bool isValidIndex(const std::string &input, int &index) const;
	std::string turncate(std::string src) const;
	size_t ft_strlen(const std::string& str) const;
};

#endif
