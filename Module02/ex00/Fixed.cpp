/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FIxed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:32:34 by mgranate          #+#    #+#             */
/*   Updated: 2023/03/30 16:32:35 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed ( void ){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( const Fixed &point){
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(point.getRawBits());
}

Fixed::~Fixed ( void ){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &point) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &point) {
		this->_fixedPoint = point.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);	
}

void    Fixed::setRawBits( int const raw ) {
    this->_fixedPoint = raw;
}