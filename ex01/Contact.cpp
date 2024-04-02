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
	while (true) {
		std::cin >> input;
		if (!input.empty()) {
			dest = input;
			break;
		}
		std::cout << "Invalid input. Please try again:\n";
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
	std::cout << "Contact " << this->first_name << " created!\n";
}

#define COLUMN_MAXLEN 10

std::string trunc_dot(const std::string &str) {
	if (str.length() > COLUMN_MAXLEN) {
		return (str.substr(0, 9) + ".");
	}
	return (str);
}

// gets formatted input of type Contact
void Contact::Display() {
	if (first_name.empty()) {
		std::cout << "Contact is empty!\n";
		return ;
	}
	std::stringstream idx_ss;
	idx_ss << this->index;
	std::cout << std::setw(10) << std::right << "index" << "|"
			  << std::setw(10) << std::right << "first name" << "|"
			  << std::setw(10) << std::right << "last name" << "|"
			  << std::setw(12) << std::right << "phone number" << "|\n";
	std::cout << std::setw(10) << std::right << idx_ss.str() << "|"
			  << std::setw(10) << std::right << trunc_dot(first_name) << "|"
			  << std::setw(10) << std::right << trunc_dot(last_name) << "|"
			  << std::setw(12) << std::right << trunc_dot(phone_number) << "|\n";
}

void Contact::add_index(int index) { this->index = index; }

// std::string Contact::get_data() {
// 	std::string data;
// 	data += first_name + "\n";
// 	data += last_name + "\n";
// 	data += nickname + "\n";
// 	data += phone_number + "\n";
// 	data += darkest_secret + "\n";
// 	return (data);
// }