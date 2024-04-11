#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : num_contacts(0) {
  for (int i = 0; i < MAX_CONTACTS; i++) {
    contact[i].add_index(i);
  }
}

PhoneBook::~PhoneBook() {}

void PhoneBook::Add() {
  if (num_contacts == MAX_CONTACTS) {
    std::cout << "Adding new contact (replacing index 0)...\n";
    contact[0].Init();
    contact[0].add_index(0);
    return;
  }
  std::cout << "Adding new contact...\n";
  contact[num_contacts].Init();
  contact[num_contacts].add_index(num_contacts);
  num_contacts++;
}

void PhoneBook::List() {
  std::cout << std::setw(5) << std::right << "index"
            << "|" << std::setw(5) << std::right << "first name"
            << "|" << std::setw(10) << std::right << "last name"
            << "|" << std::setw(12) << std::right << "phone number\n";
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
