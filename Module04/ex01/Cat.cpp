#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "[Cat Default Constructer " << this->type << "]" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain;
	this->_brain->getBrainIdeas();
}

Cat::Cat(const Cat& other) : Animal(other.type) {
	std::cout << "[Cat Copy Constructer " << this->type << "]" << std::endl;
	this->type = other.type;
	this->_brain = new Brain;
}

Cat& Cat::operator=(const Cat& other)  {
	std::cout << "[Cat Assignment Operator Constructer " << this->type << "]" << std::endl;
	if (this != &other)
	{
		if (this->_brain)
			delete _brain;
		this->_brain = new Brain;
		this->type = other.type;
	}
    return *this;
}

Cat::Cat(std::string name) : Animal(name) {
	std::cout << "[Cat Name Constructor " << this->type << "]" << std::endl;	
	this->type = name;
	this->_brain = new Brain;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "[Cat Destructer " << this->type << "]" << std::endl;
}

std::string	Cat::getType() const{
	return (this->type);
}


void	Cat::makeSound() const {
	std::cout << "Cat Miaus: Miau Miau" << std::endl;	
}