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
		if (input == "ADD")
			phone.add();
		if (input == "SEARCH")
			phone.search();
		std::cout << "> Anything else I can do for you: ";
	}
	std::cout << "Hope to see you again soon!" << std::endl;
}