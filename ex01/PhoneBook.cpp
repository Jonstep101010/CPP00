#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

PhoneBook::PhoneBook() { num_contacts = 0; }

PhoneBook::~PhoneBook() { }

void PhoneBook::Add() {
	if (num_contacts == MAX_CONTACTS) {
		std::cout << "Adding new contact (replacing index 0)...\n";
		contact[0].Init();
		contact[0].add_index(0);
		return ;
	}
	std::cout << "Adding new contact...\n";
	contact[num_contacts].Init();
	contact[num_contacts].add_index(num_contacts);
	num_contacts++;
}

void PhoneBook::Search() {
	if (num_contacts > 0) {
		std::cout << "Provide the search index:\n";
		std::string field;
		std::cin >> field;
		int search_index = atoi(field.c_str());

		if (search_index >= 0 && search_index <= num_contacts) {
			std::cout << "Table for index " + field + "\n";
			contact[search_index].Display();
		}
		else {
			std::cout << "The range is from 0 to 7\n";
		}
	}
	else {
		std::cout << "Phonebook is empty!\n";
	}
}
