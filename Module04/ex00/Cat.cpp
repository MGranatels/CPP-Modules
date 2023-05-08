#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "[Cat Default Constructer " << this->type << "]" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other.type) {
	std::cout << "[Cat Copy Constructer " << this->type << "]" << std::endl;
	this->type = other.type;
}

Cat& Cat::operator=(const Cat& other)  {
	std::cout << "[Cat Assignment Operator Constructer " << this->type << "]" << std::endl;
	this->type = other.type;

    return *this;
}

Cat::Cat(std::string name) : Animal(name) {
	std::cout << "[Cat Name Constructor " << this->type << "]" << std::endl;	
	this->type = name;
}

Cat::~Cat() {
	std::cout << "[Cat Destructer " << this->type << "]" << std::endl;
}

std::string	Cat::getType() const{
	return (this->type);
}


void	Cat::makeSound() const {
	std::cout << "Cat Miaus: Miau Miau" << std::endl;	
}