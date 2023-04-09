#include "Phonebook.hpp"
#include "Contact.hpp"

int	main(void)
{
	Phonebook phone;
	std::string input;
	int			exit;

	exit = 1;
	std::cout << "> Welcome to the Phoneight, how may I help you today: ";
	while (exit)
	{
		std::getline (std::cin, input);
		if (input == "EXIT")
			exit = 0;
		else if (input == "ADD") {
			phone.add();
			std::cout << "> Anything else I can do for you: ";
		}
		else if (input == "SEARCH") {
			phone.search();
			std::cout << "> Anything else I can do for you: ";
		}
		else
			std::cout << "Wrong Input. Try Again: ";
	}
	std::cout << "Hope to see you again soon!" << std::endl;
}