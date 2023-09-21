#include <PmergeMe.hpp>

int	main(int ac, char **av)
{	
	std::string	concat;
	
	if (ac < 2)
	{
		std::cout << "Incorrect parameters" << std::endl;
		return 1;
	}
	for (int i = 1; i < ac; i++)
		concat += " " + std::string(av[i]);
	PmergeMe letsSort(concat);
}