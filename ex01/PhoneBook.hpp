#pragma once

#include "Contact.hpp"

#define MAX_CONTACTS 1

class PhoneBook {
private:
	Contact contact[MAX_CONTACTS];
	int     num_contacts;
	int     contact_index;

public:
	PhoneBook();
	~PhoneBook();
	void Add();
	void Search();
	void List();
};
