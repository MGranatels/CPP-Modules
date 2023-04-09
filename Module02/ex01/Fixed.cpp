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

Fixed::Fixed( const int _nb )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = _nb;
}

Fixed::Fixed (const float _nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = _nb;
}

Fixed& Fixed::operator=(const Fixed &point) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &point) {
		this->_fixedPoint = point.getRawBits();
	}
	return *this;
}


Fixed::~Fixed ( void ){
	std::cout << "Destructor called" << std::endl;
}


int	Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);	
}

void    Fixed::setRawBits( int const raw ) {
    this->_fixedPoint = raw;
}

float Fixed::toFloat( void ) const {
    return ((float)this->_fixedPoint / (1 << this->_bit));
}

int Fixed::toInt( void ) const {
    return (this->_fixedPoint >> this->_bit);
}