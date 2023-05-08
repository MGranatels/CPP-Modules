#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[Brain Default Constructer]" << std::endl;
}

Brain::Brain(const Brain& copy) {
	std::cout << "[Brain Copy Constructer]" << std::endl;
	for (int i = 0; i < 100; i++){
		this->ideas[i] = copy.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& assign) {
	for (int i =0; i < 100; i++)
		this->ideas[i] = assign.ideas[i];
	return *this;
}

Brain::~Brain() {
    // Destructor code here
}
