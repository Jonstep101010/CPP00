#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

Contact::Contact() { };

Contact::~Contact() { };

void Contact::add_item(const std::string& item, std::string &dest) {
    std::string input;
    std::cout << "Please provide your " << item << ":\n";
    std::cin >> input;
    while (true) {
        if (!input.empty()) {
            dest = input;
            break;
        }
        if (input.empty()) {
            std::cout << "Invalid input. Please try again:\n";
            std::cin >> input;
        }
    }
}

void Contact::Init() {
	while (true) {
		this->add_item("first name", first_name);
		this->add_item("last name", last_name);
        this->add_item("nickname", nickname);
        this->add_item("number", phone_number);
        this->add_item("darkest secret", darkest_secret);
        break;
	}
    std::cout << "Contact " << this->get_first_name() << " created!\n";
}

void Contact::Display() {
    std::stringstream ss;
    ss << this->index;
    std::string index_str = ss.str();
    if (first_name.empty()) {
        std::cout << "Contact is empty!\n";
        return;
        index_str = "0";
    }
	std::cout << std::setw(5) << std::right << "index" << "|"
              << std::setw(10) << std::right << "first name" << "|"
              << std::setw(10) << std::right << "last name" << "|"
              << std::setw(12) << std::right << "phone number" << "|\n";
    std::cout << std::setw(5) << std::right << index_str << "|"
              << std::setw(10) << std::right << first_name << "|"
              << std::setw(10) << std::right << last_name << "|"
              << std::setw(12) << std::right << phone_number << "|\n";
}

std::string Contact::get_first_name() { return (first_name); }

void Contact::add_index(int index) { this->index = index; }

std::string Contact::get_data() {
    std::string data;
    data += first_name + "\n";
    data += last_name + "\n";
    data += nickname + "\n";
    data += phone_number + "\n";
    data += darkest_secret + "\n";
    return (data);
}