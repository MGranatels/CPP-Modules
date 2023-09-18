#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:

    WrongCat();
    WrongCat(const WrongCat& copy);
    WrongCat(std::string name);
    WrongCat& operator=(const WrongCat& assign);
    ~WrongCat();

	virtual void	makeSound() const;
	virtual std::string	getType( void ) const;
};

#endif 
