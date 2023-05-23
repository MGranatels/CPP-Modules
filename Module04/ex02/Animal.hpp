/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:44:37 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/05/07 15:44:38 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_HPP
#define Animal_HPP

#include <iostream>

class Animal {
private:

protected:
    std::string type;
	std::string _name;

public:

    Animal();
    Animal(const Animal& other);
	Animal(std::string name);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

	virtual void	makeSound() const = 0;
	virtual std::string	getType( void ) const = 0;
    // By assigning it to zero it becames a pure virtual function. 
	// This means I indicate the program that the function has no implementation
	// in the Animal class and must be overridden by any derived class.
};

#endif // Animal_HPP
