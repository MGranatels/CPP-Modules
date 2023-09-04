#include "ScalarConverter.hpp"

int	main (int ac, char **av)
{
	if (ac != 2)
		return 0;
	ScalarConverter::convertChar(std::string(av[1]));
	return 1;	
}