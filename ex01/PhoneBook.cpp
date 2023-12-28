#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

PhoneBook::PhoneBook() { num_contacts = 0; }

PhoneBook::~PhoneBook() { }

void PhoneBook::Add_Contact() {
    if (num_contacts == MAX_CONTACTS) {
        std::cout << "Phonebook is full!\n";
        return;
    }
	std::cout << "Adding new contact...\n";
	contact[num_contacts].Init();
    contact[num_contacts].add_index(num_contacts);
    num_contacts++;
}

void PhoneBook::Search() {
    if (num_contacts == 0) {
        std::cout << "Phonebook is empty!\n";
        return;
    }
	std::cout << "Provide the search index:\n";
	std::string input;
	std::cin >> input;
	int search_index = std::atoi(input.c_str());
	if (search_index < 0 || search_index > 7 || search_index > num_contacts) {
		std::cout << "The range is from 0 to 7\n";
	}
	else {
		std::cout << "Table for index " + input + "\n";
	}
	contact[search_index].Display();
	// contact[0].Display();
}