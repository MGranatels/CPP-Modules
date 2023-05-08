#include "FragTrap.hpp"

FragTrap::FragTrap () : ClapTrap(){
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap ( std::string name) : ClapTrap(name){
 	std::cout << "FragTrap Name constructor called" << std::endl;
	this->_guardGate = 0;
}

FragTrap::~FragTrap ( void ){
 	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::string _input;
	std::cout << std::endl << "---------- " << this->getName() << " High Five ----------" << std::endl;
 	std::cout << "FragTrap Requests a High Five! " << std::endl;
 	std::cout << "Press Enter to Respond:  " << std::endl;
	std::getline(std::cin, _input);
	std::cout << "---------- " << this->getName() << " End Action -------------" << std::endl;
}