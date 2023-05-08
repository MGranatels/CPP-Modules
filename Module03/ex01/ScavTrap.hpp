#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	private:
		int	_guardGate;
	public:
		ScavTrap ( void );
		ScavTrap( std::string name );
		ScavTrap (const ScavTrap &point);
		ScavTrap& operator= (const ScavTrap& param);
		virtual void	attack(const std::string& target);
		~ScavTrap( void );

		void	guardGate( void );
		void	setGuard( unsigned int value );
		int		getGuard( void ) const;
};

int		checkDeath(ClapTrap &user, ScavTrap &enemy);

#endif