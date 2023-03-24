#include "Phonebook.hpp"
#include "Contact.hpp"

int	check_user_input(std::string input, Phonebook phone)
{
	static int	i;
	if (!input.compare("EXIT"))
	{
		std::cout << "Hope to see you again soon!" << std::endl;
		return (0);
	}
	if (!input.compare("ADD"))
	{
		phone.add_contact(i);
		
	}
	if (!input.compare("SEARCH"))
		std::cout << "Your gonna look for something" << std::endl;
	return (1);
}

int	main(void)
{
	Phonebook phone;
	std::string input;
	int			exit;

	exit = 1;
	while (exit)
	{
		std::cout << "Welcome to the Phoneight, how may I help you today: ";
		std::getline (std::cin, input);
		exit = check_user_input(input, phone);
	}
}