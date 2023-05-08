#include "Animal.hpp"

Animal::Animal() : type("No type defined yet") {
		std::cout << "[Animal Default Constructor " << this->type << "]" << std::endl;	
}

Animal::Animal(std::string name) : type(name) {
	std::cout << "[Animal Name Constructor " << this->type << "]" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "[Animal Copy Constructer " << this->type << "]" << std::endl;
	this->type = other.type;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "[Animal Assignment Operator Constructer "  << this->type << "]" << std::endl;
	this->type = other.type;
    return *this;
}

Animal::~Animal() {
	std::cout << "[Animal Destructer "  << this->type << "]" << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "Animals make sounds but this one makes none at all" << std::endl;	
}

std::string	Animal::getType() const{
	return (this->type);
}