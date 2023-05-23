#include "Dog.hpp"

Dog::Dog( void ) : Animal() {
   	std::cout << "[Dog Default Constructer "  << this->type << "]" << std::endl;
	this->_brain = new Brain;
}

Dog::Dog(std::string name) : Animal(name) {
	std::cout << "[Dog Name Constructor " << this->type << "]" << std::endl;	
	this->type = name;
	this->_brain = new Brain;
}

Dog::Dog(const Dog& other) : Animal(other.type) {
	std::cout << "[Dog Copy Constructer " << this->type << "]" << std::endl;
	this->type = other.type;
	this->_brain = new Brain;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "[Dog Assignment Operator Constructer" << this->type << "]" << std::endl;
	if (this != &other)
	{
		if (this->_brain)
			delete _brain;
		this->_brain = new Brain;
		this->type = other.type;
	}
    return *this;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "[Dog Destructer " << this->type << "]" << std::endl;
}

std::string	Dog::getType() const{
	return (this->type);
}

void	Dog::makeSound() const {
	std::cout << this->type << " woof woof" << std::endl;	
}
