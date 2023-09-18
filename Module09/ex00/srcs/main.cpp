#include <BitcoinExchange.hpp>

int	main(int ac, char **av)
{	
	(void) av;
	if (ac != 2)
	{
		std::cout << "Not enought arguments" << std::endl;
		return 1;
	}
	BitcoinExchange letsExchange(av[1]);
}