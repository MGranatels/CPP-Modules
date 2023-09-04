#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Ideia";
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain& copy) {
	for (int i = 0; i < 100; i++){
		this->ideas[i] = copy.ideas[i];
	}
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}

Brain& Brain::operator=(const Brain& assign) {
	for (int i =0; i < 100; i++)
		this->ideas[i] = assign.ideas[i];
	return *this;
}

Brain::~Brain() {
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}

void	Brain::getBrainIdeas() {
	for (int i =0; i < 100; i++)
		std::cout << i << " number: "<< this->ideas[i] << std::endl;
}