#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap{
	private:
		int	_guardGate;
	public:
		FragTrap ( void );
		FragTrap( std::string name );
		FragTrap (const FragTrap &point);
		FragTrap& operator= (const FragTrap& param);
		~FragTrap( void );
		
		void highFivesGuys(void);
};

#endif