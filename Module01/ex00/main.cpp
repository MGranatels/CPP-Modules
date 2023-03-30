#include "Zombie.hpp"

Zombie* newZombie( std::string name );

int	main()
{
	Zombie *zom;

	zom = newZombie("Zoriii");
	zom->announce();
	randomChump("Greg");
	delete zom;
}