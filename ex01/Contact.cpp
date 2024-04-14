#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

Contact::Contact()
	: index(-1) {}

Contact::~Contact() {}

static bool validate_input(const std::string& item,
						   const std::string& input) {
	if (input.empty()) {
		std::cout << "Invalid: Input cannot be empty!\n";
		return false;
	}
	if (item == "number") {
		for (size_t i = 0; i < input.length(); i++) {
			if (isdigit(input[i]) == 0) {
				std::cout << "Invalid: Input must be numeric!\n";
				return false;
			}
		}
	}
	return true;
}

void Contact::add_item(const std::string& item,
					   std::string&       dest) {
	std::string input;
	std::cout << "Please provide your " << item << ":\n";
	while (!std::cin.eof()) {
		std::cin >> input;
		if (validate_input(item, input)) {
			dest = input;
			break;
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
	std::cout << "Contact " << this->first_name << " created!\n";
}

#define COLUMN_MAXLEN 10

std::string trunc_dot(const std::string& str) {
	if (str.length() > COLUMN_MAXLEN) {
		return (str.substr(0, COLUMN_MAXLEN - 1) + ".");
	}
	return (str);
}

// gets formatted input of type Contact
void Contact::RowDisplay() {
	std::cout << std::setw(10) << std::right << this->index
			  << "|" << std::setw(10) << trunc_dot(first_name)
			  << "|" << std::setw(10) << trunc_dot(last_name)
			  << "|" << std::setw(10) << trunc_dot(nickname)
			  << std::endl;
}

void Contact::Display() {
	const int labelWidth = 16;
	const int valueWidth = 20;
	std::cout << std::setw(labelWidth) << std::left
			  << "First Name: " << std::setw(valueWidth)
			  << std::left << first_name << '\n';
	std::cout << std::setw(labelWidth) << std::left
			  << "Last Name: " << std::setw(valueWidth)
			  << std::left << last_name << '\n';
	std::cout << std::setw(labelWidth) << std::left
			  << "Nickname: " << std::setw(valueWidth)
			  << std::left << nickname << '\n';
	std::cout << std::setw(labelWidth) << std::left
			  << "Phone Number: " << std::setw(valueWidth)
			  << std::left << phone_number << '\n';
	std::cout << std::setw(labelWidth) << std::left
			  << "Darkest Secret: " << std::setw(valueWidth)
			  << std::left << darkest_secret << '\n';
}

void Contact::add_index(int index) { this->index = index; }