#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

PhoneBook::PhoneBook()
	: num_contacts(0), contact_index(0) {
	for (int i = 0; i < MAX_CONTACTS; i++) {
		contact[i].add_index(i);
	}
}

PhoneBook::~PhoneBook() {}

void PhoneBook::Add() {
	std::cout << "Adding new contact...\n";
	if (num_contacts == MAX_CONTACTS) {
		std::cout << "Replacing oldest contact...\n";
		contact_index = 0;
	}
	contact[contact_index].Init();
	contact[contact_index].add_index(contact_index);
	if (num_contacts >= MAX_CONTACTS) {
		contact_index = 0;
		num_contacts  = MAX_CONTACTS;
	} else {
		contact_index = num_contacts;
		num_contacts++;
	}
	contact_index++;
}

void PhoneBook::List() {
	std::cout << std::setw(10) << std::right << "index"
			  << "|" << std::setw(10) << "first name"
			  << "|" << std::setw(10) << "last name"
			  << "|" << std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++) {
		contact[i].RowDisplay();
	}
}

void PhoneBook::Search() {
	std::cout << "Provide the search index: ";
	while (true) {
		std::string field;
		std::cin >> field;
		int search_index = atoi(field.c_str());

		if (search_index < 0 || search_index >= MAX_CONTACTS) {
			std::cout << "The range is from 0 to 7. Retry:\n";
		} else {
			std::cout << "Table for index " + field + ":\n";
			contact[search_index].Display();
			return;
		}
	}
}
