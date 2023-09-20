#include <RPN.hpp>

int	main(int ac, char **av)
{	
	(void) av;
	if (ac != 2)
	{
		std::cout << "Incorrect parameters" << std::endl;
		return 1;
	}
	RPN letsCalculate(av[1]);
}