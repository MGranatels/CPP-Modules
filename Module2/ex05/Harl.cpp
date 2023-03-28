#include "Harl.hpp"

void    Harl::debug( void ) {
    std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info( void ) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! "
			  << "If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning( void ) {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started " 
	<< "working here since last month." << std::endl;
}

void    Harl::error( void ) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


Harl::Harl() {
}

Harl::~Harl() {
    // Destructor code here
}

void	Harl::complain( std::string level )
{
	int			i = 0;
	t_func 		func[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string lvl[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (i < 4 && lvl[i].compare(level))
		i++;
	if (i < 4)
		(this->*func[i])();
}
