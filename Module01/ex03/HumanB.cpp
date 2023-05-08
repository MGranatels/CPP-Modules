#include "HumanB.hpp"

HumanB::HumanB( std::string name) : _name(name){
	this->_weapon = NULL;
}

HumanB::~HumanB() {
}

void	HumanB::setWeapon(Weapon& weapon){
	this->_weapon = &weapon;
}

void    HumanB::attack( void ) const {
    if (this->_weapon != NULL && this->_weapon->getType() != "") {
        std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
    } else {
        std::cout << _name << " doesn't have a weapon to attack." << std::endl;
    }
}

void	HumanB::setHp ( int hit )
{
	std::cout << _name << " has taken" << hit << " Damage" << std::endl;
	this->_hp -= hit;
	if (this->_hp <= 0)
		std::cout << _name << " Is Dead" << std::endl;
}

const int	HumanA::check_hp ( void )
{
	return (this->_hp);
}