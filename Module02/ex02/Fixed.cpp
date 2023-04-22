/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:32:34 by mgranate          #+#    #+#             */
/*   Updated: 2023/04/22 16:14:37 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	//std::cout << "Default constructor called" << std::endl;
	this->_fixedNum = 0;
}

Fixed::Fixed(const Fixed& param) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = param;
}

Fixed::Fixed(const int num){
	//std::cout << "Int constructor called" << std::endl;
	this->_fixedNum = num << this->_fractional_bits;
}

Fixed::Fixed(const float num){
	//std::cout << "Float constructor called" << std::endl;
	this->_fixedNum = roundf(num * pow(2, this->_fractional_bits));
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& param)
{
	//std::cout << "Copy assignment operator called" << std::endl;
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

bool Fixed::operator> (Fixed const &value)
{
	if (this->toFloat() > value.toFloat())
		return (true);	
	return (false);
}

bool Fixed::operator>= (Fixed const &value)
{
	if (this->toFloat() >= value.toFloat())
		return (true);	
	return (false);
}

bool Fixed::operator< (Fixed const &value)
{
	if (this->toFloat() < value.toFloat())
		return (true);	
	return (false);
}

bool Fixed::operator<= (Fixed const &value)
{
	if (this->toFloat() <= value.toFloat())
		return (true);	
	return (false);
}

bool Fixed::operator== (Fixed const &value)
{
	if (this->toFloat() == value.toFloat())
		return (true);	
	return (false);
}

bool Fixed::operator!= (Fixed const &value)
{
	if (this->toFloat() != value.toFloat())
		return (true);	
	return (false);
}


Fixed Fixed::operator*(Fixed const &value)
{
	Fixed result = Fixed(this->toFloat() * value.toFloat());

	return(result);
}

Fixed Fixed::operator+(Fixed const &value)
{
	Fixed result = Fixed(this->toFloat() + value.toFloat());

	return(result);
}

Fixed Fixed::operator-(Fixed const &value)
{
	Fixed result = Fixed(this->toFloat() - value.toFloat());

	return(result);
}

Fixed Fixed::operator/(Fixed const &value)
{
	Fixed result = Fixed(this->toFloat() / value.toFloat());

	return(result);
}

Fixed Fixed::operator++(int)
{
	Fixed result;
	
	result.setRawBits(this->_fixedNum);
	this->_fixedNum++;
	return(result);
}

Fixed Fixed::operator++()
{
	this->_fixedNum++;
	return(*this);
}


Fixed Fixed::operator--(int)
{
	Fixed result;
	
	result.setRawBits(this->_fixedNum);
	this->_fixedNum--;
	return(result);
}

Fixed Fixed::operator--()
{
	this->_fixedNum--;
	return(*this);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	if ((Fixed &)a < (Fixed &)b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	if ((Fixed &)a > (Fixed &)b)
		return (a);
	return (b);
}