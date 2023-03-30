#include <iostream>

void	to_upper(char *s)
{
	int	j;

	j = -1;
	while (s[++j])
		std::cout << (char)toupper(s[j]);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	i = 0;
	while (av[++i])
		to_upper(av[i]);
	std::cout << std::endl;
}