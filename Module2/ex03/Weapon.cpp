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