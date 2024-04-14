#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

void loop(PhoneBook my_phonebook) {
	std::string cmd;

	while (true) {
		std::cout << "Enter your command:\n";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT" || std::cin.eof()) {
			return;
		}
		if (cmd == "ADD") {
			my_phonebook.Add();
		} else if (cmd == "SEARCH") {
			my_phonebook.List();
			my_phonebook.Search();
			std::cin.ignore(
				std::numeric_limits<std::streamsize>::max(),
				'\n');
		} else {
			std::cout << "Invalid command.\n";
		}
	}
}

int main() {
	PhoneBook my_phonebook;

	loop(my_phonebook);
	std::cout << "Goodbye!\n";
	return (0);
}