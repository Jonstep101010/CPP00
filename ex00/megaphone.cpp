#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

int	main(int ac, char **av) {
	if (ac > 1)
	{
		std::string input;
		for (int i = 1; i < ac; ++i) {
			input += av[i];}
		for (std::string::size_type i = 0; i < input.length(); ++i) {
			input[i] = std::toupper(input[i]);}
		std::cout << input << "\n";
	}
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";}
	return 0;
}