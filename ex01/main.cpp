#include "PhoneBook.hpp"
#include <iostream>

void	loop(PhoneBook my_phonebook)
{
	std::string cmd;

	while (1)
	{
		std::cout << "Enter your command:\n";
		std::cin >> cmd;
		if (cmd == "EXIT")
			return ;
		if (cmd == "ADD")
			my_phonebook.Add();
		else if (cmd == "SEARCH")
			my_phonebook.Search();
		else
            std::cout << "Invalid command.\n";
	}
}

int main() {
	PhoneBook my_phonebook;

	loop(my_phonebook);
    std::cout << "Goodbye!\n";
	return (0);
}