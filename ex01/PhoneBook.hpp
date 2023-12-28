#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

const int MAX_CONTACTS = 8;

class PhoneBook {
private:
	Contact contact[MAX_CONTACTS];
	int num_contacts;
	// int index;

public:
	PhoneBook();
	~PhoneBook();
	void Add_Contact();
	void Search();
};

#endif