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
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal& other);
	Animal(std::string name);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

	virtual void	makeSound() const;
	virtual std::string	getType( void ) const;
    // Member function declarations here
};

#endif // Animal_HPP
