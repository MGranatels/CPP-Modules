#include "ScavTrap.hpp"

ScavTrap::ScavTrap () : ClapTrap(){
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap ( std::string name) : ClapTrap(name){
 	std::cout << "ScavTrap Name constructor called" << std::endl;
	this->_guardGate = 0;
}

ScavTrap::~ScavTrap ( void ){
 	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::attack ( const std::string& target)
{
	std::cout << std::endl << "---------- " << this->getName() << " Attacks ----------" << std::endl;
	if (this->getEnergy() <= 0)
	{
		std::cout << "> SlapTrap" << this->getName() << " Does not have enought energy" << std::endl;
		this->setEnergy(this->getEnergy() - 1);
		return ;
	}
	std::cout << "> SlapTrap " << this->getName() << " attacks " << target << " causing " << this->getDamage() << " points of damage!" << std::endl;
	this->setEnergy(this->getEnergy() - 1);
	std::cout << "---------- " << this->getName() << " End Attack -------------" << std::endl;
}

void	ScavTrap::guardGate( void ){
	std::cout << std::endl << "---------- " << this->getName() << " Guard Gate ----------" << std::endl;
	std::cout << "> SlapTrap is in Gate Keeper Mode" << this->getName() << " and Becames Invulnerable" << std::endl;
	std::cout << "---------- " << this->getName() << " End Action -------------" << std::endl;
	this->_guardGate = 1;
}

void	ScavTrap::setGuard( unsigned int value ) {
	this->_guardGate = value;
}

int	ScavTrap::getGuard( void ) const{
	return (this->_guardGate);
}