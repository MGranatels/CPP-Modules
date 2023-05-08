#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
	FragTrap var;
	std::cout << "DiamondTrap Name constructor called" << std::endl;

	this->_hit_Points = var.getHit ();
	this->_attack_Damage = ScavTrap::_attack_Damage;
	this->_energy_Points = var.getEnergy ();
}

DiamondTrap::~DiamondTrap ( void ){
 	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::WhoAmI( void ){
	std::cout << "I am a DiamondTrap named: " << this->_name << ", Clap Trap name: " << ClapTrap::_name << std::endl;
}