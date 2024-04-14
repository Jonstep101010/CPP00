#pragma once

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
private:
	Contact contact[MAX_CONTACTS];
	int     num_contacts;

public:
	PhoneBook();
	~PhoneBook();
	void Add();
	void Search();
	void List();
};
