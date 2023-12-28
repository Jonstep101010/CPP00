#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main() {
	PhoneBook my_phonebook;

    // my_phonebook.Search();
    // return (0);
	std::string cmd;
	while (cmd != "EXIT") {
		std::cout << "Enter your command:\n";
		std::cin >> cmd;
		if (cmd == "ADD") {
			my_phonebook.Add_Contact();
		} else if (cmd == "SEARCH") {
			my_phonebook.Search();
		} else if (cmd == "EXIT") {
            std::cout << "Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid command.\n";
        }
	}
	return (0);
}