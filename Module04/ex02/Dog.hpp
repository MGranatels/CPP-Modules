#ifndef DOG_HPP
#define DOG_HPP

#include "Cat.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain *_brain;

public:
    Dog( void );
    Dog(const Dog& other);
	Dog(std::string name);
    Dog& operator=(const Dog& other);
    ~Dog();

	virtual void	makeSound() const;
	virtual std::string	getType( void ) const;
    // Member function declarations here
};

#endif // Dog_HPP
