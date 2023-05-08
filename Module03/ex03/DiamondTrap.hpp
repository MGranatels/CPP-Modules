
#include "FragTrap.hpp"

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string _name;
	public:
		 DiamondTrap(std::string name);
		 ~DiamondTrap();

		 using	ScavTrap::attack;
		 void	WhoAmI ( void );
};

int		checkDeath(ClapTrap &user, FragTrap &enemy);

#endif