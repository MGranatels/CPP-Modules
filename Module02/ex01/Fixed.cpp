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

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& param) {
	std::cout << "Copy constructor called" << std::endl;
	*this = param;
}

Fixed::Fixed(const int num){
	std::cout << "Int constructor called" << std::endl;
	this->_fixedNum = num << this->_fractional_bits;
}

Fixed::Fixed(const float num){
	std::cout << "Float constructor called" << std::endl;
	this->_fixedNum = roundf(num * pow(2, this->_fractional_bits));
	std::cout << "FLota Const tester: " << this->_fixedNum;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& param)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedNum = param.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const{
	return(this->_fixedNum);
}

void Fixed::setRawBits( int const raw ){
	this->_fixedNum = raw;
}

float	Fixed::toFloat(void) const{
	return (this->_fixedNum / pow(2, this->_fractional_bits));
}

int		Fixed::toInt(void) const{
	return (this->_fixedNum >> this->_fractional_bits);
}

std::ostream&	operator<<(std::ostream& cout, const Fixed& num){
	cout << num.toFloat();

	return (cout);
}