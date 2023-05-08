#include "Dog.hpp"

Dog::Dog() : Animal() {
   	std::cout << "[Dog Default Constructer "  << this->type << "]" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other.type) {
	std::cout << "[Dog Copy Constructer " << this->type << "]" << std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "[Dog Assignment Operator Constructer" << this->type << "]" << std::endl;
	this->type = other.type;

    return *this;
}
Dog::Dog(std::string name) : Animal(name) {
	std::cout << "[Dog Name Constructor " << this->type << "]" << std::endl;	
	this->type = name;
}

Dog::~Dog() {
	std::cout << "[Dog Destructer " << this->type << "]" << std::endl;

}

std::string	Dog::getType() const{
	return (this->type);
}

void	Dog::makeSound() const {
	std::cout << "Dog Barks: woof woof" << std::endl;	
}