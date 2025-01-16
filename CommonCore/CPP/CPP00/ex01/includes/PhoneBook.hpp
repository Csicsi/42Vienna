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
	bool isValidIndex(const std::string &input, int &index) const;
};

#endif
