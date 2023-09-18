/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:44:27 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/05/07 15:50:14 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "[WrongCat Default Constructer " << this->type << "]" << std::endl;
	this->type = "Dog";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy.type) {
	std::cout << "[WrongCat Copy Constructer " << this->type << "]" << std::endl;
	this->type = copy.type;
}

WrongCat& WrongCat::operator=(const WrongCat& assign) {
	std::cout << "[WrongCat Assignment Operator Constructer " << this->type << "]" << std::endl;
	this->type = assign.type;

    return *this;
}
WrongCat::WrongCat(std::string name) : WrongAnimal(name) {
	std::cout << "[Cat Name Constructor " << this->type << "]" << std::endl;	
	this->type = name;
}

WrongCat::~WrongCat() {
	std::cout << "[WrongCat Destructer " << this->type << "]" << std::endl;
}

std::string	WrongCat::getType() const{
	return (this->type);
}

void	WrongCat::makeSound() const {
	std::cout << "Cat Now Barks: woof woof " << std::endl;	
}