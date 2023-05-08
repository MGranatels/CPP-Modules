/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:32:34 by mgranate          #+#    #+#             */
/*   Updated: 2023/04/23 20:48:23 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( std::string name ){
	//std::cout << "Default constructor called" << std::endl;
	this->_attack_Damage = 0;
	this->_energy_Points = 10;
	this->_hit_Points = 10;
	this->_name = name;
}

ClapTrap::ClapTrap ( int enemy ){
	switch (enemy){
		case 1:
			std::cout << "Hermes Is called to the arena!" << std::endl;
			this->_name = "Hermes";
			this->_attack_Damage = 1;
			this->_energy_Points = 10;
			this->_hit_Points = 10;
		break ;
		case 2:
			std::cout << "Afrodite Is called to the Arena!" << std::endl;
			this->_name = "Afrodite";
			this->_attack_Damage = 3;
			this->_energy_Points = 15;
			this->_hit_Points = 20;
		break ;		
		case 3:
			std::cout << "Ares Is called to the Arena!" << std::endl;
			this->_name = "Ares";
			this->_attack_Damage = 5;
			this->_energy_Points = 20;
			this->_hit_Points = 25;
		break ;
		case 4:
			std::cout << "Zeus Is called to the Arena!" << std::endl;
			this->_name = "Zeus";
			this->_attack_Damage = 7;
			this->_energy_Points = 25;
			this->_hit_Points = 40;
		break ;
	}
}
ClapTrap::ClapTrap ( const ClapTrap &point){
	//std::cout << "Copy constructor called" << std::endl;
	*this = point;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& param)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_attack_Damage = param.getDamage();
	this->_hit_Points = param.getHit();
	this->_energy_Points = param.getEnergy();
	this->_name = param.getName();
	return (*this);
}
ClapTrap::~ClapTrap ( void ){
	//std::cout << "Destructor called" << std::endl;
}

std::string	ClapTrap::getName( void ) const{
	return (this->_name);	
}

void	ClapTrap::setName( std::string const value ) {
	this->_name = value;
}

int	ClapTrap::getDamage( void ) const{
	return (this->_attack_Damage);	
}

void    ClapTrap::setDamage( int const value ) {
    this->_attack_Damage = value;
}

int	ClapTrap::getHit( void ) const{
	return (this->_hit_Points);	
}

void    ClapTrap::setHit( int const value ) {
    this->_hit_Points = value;
}

int	ClapTrap::getEnergy( void ) const{
	return (this->_energy_Points);	
}

void    ClapTrap::setEnergy( int const value ) {
    this->_energy_Points = value;
}