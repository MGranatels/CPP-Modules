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
	switch (i + 1){
		case 1:
			std::cout << "[DEBUG]" << std::endl;
			for (int i = 0; i < 4; i++){
				(this->*func[i])();
			}
			break ;
		case 2:
			std::cout << "[INFO]" << std::endl;
			for (int i = 1; i < 4; i++){
				(this->*func[i])();
			}
			break ;
		case 3:
			std::cout << "[WARNING]" << std::endl;
			for (int i = 2; i < 4; i++){
				(this->*func[i])();
			}
			break ;
		case 4:
			std::cout << "[ERROR]" << std::endl;
			for (int i = 3; i < 4; i++){
				(this->*func[i])();
			}
			break ;
		default:
			std::cout << "Invalid Choice" << std::endl;
	}
}