#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Unknown WrongAnimal") {
	std::cout << "[Wrong Animal Default Constructor " << this->type << "]" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : type(name) {
	std::cout << "[Wrong Animal Name Constructor " << this->type << "]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	std::cout << "[Wrong Animal Copy Constructer " << this->type << "]" << std::endl;
	this->type = copy.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& assign) {
	std::cout << "[Wrong Animal Assignment Operator Constructer "  << this->type << "]" << std::endl;
    this->type = assign.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[Wrong Animal Destructer "  << this->type << "]" << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "Wrong Animal Sound" << std::endl;	
}

std::string	WrongAnimal::getType() const{
	return (this->type);
}