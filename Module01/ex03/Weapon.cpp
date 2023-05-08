#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->setType(type);
}

Weapon::~Weapon() {
    // Destructor code here
}

const  std::string Weapon::getType( void ) {
    return this->_type;
}

void                Weapon::setType( std::string newType ) {
    this->_type = newType;
}


int		Weapon::weapon_damage( int value )
{
	if (this->_type == "Long Sword")
		return (50);
	if (this->_type == "Axe")
		return (40);
	if (this->_type == "Hammer")
		return (70);
	if (this->_type == "Staff")
		return (20);
	return (0);
}
