/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:32:34 by mgranate          #+#    #+#             */
/*   Updated: 2023/05/06 18:20:54 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
ClapTrap::ClapTrap ( void )
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	this->_attack_Damage = 10;
	this->_energy_Points = 10;
	this->_hit_Points = 10;
}

ClapTrap::ClapTrap ( std::string name ){
	std::cout << "ClapTrap Name constructor called" << std::endl;
	this->_attack_Damage = 10;
	this->_energy_Points = 10;
	this->_hit_Points = 10;
	this->_name = name;
}

ClapTrap::ClapTrap ( const ClapTrap &point){
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = point;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& param)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	this->_attack_Damage = param.getDamage();
	this->_hit_Points = param.getHit();
	this->_energy_Points = param.getEnergy();
	return (*this);
}
ClapTrap::~ClapTrap ( void ){
	std::cout << "ClapTrap Destructor called" << std::endl;
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

void	ClapTrap::beRepaired (unsigned int amount)
{
	std::cout << std::endl << "------- "<< this->getName() << " RESTORE HEALTH -------" << std::endl;
	if (this->getEnergy() <= 0)
	{
		std::cout<< "> " << this->_name << " Does not have enought energy" << std::endl;
		this->setEnergy(this->getEnergy() - 1);
		return ;
	}
	this->setHit(this->getHit() + amount);
	std::cout  << "> ClapTrap " << this->getName()  << " Restores " << amount << "Hp" << std::endl;
	std::cout  << "> ClapTrap " << this->getName()  << " Now Has " << this->getHit() << "Hp" << std::endl;
	this->setEnergy(this->getEnergy() - 1);
	std::cout << "---------- END RESTORE ACTION -------------" << std::endl << std::endl;
}

void	ClapTrap::attack ( const std::string& target)
{
	std::cout << std::endl << "---------- " << this->getName() << " Attacks ----------" << std::endl;
	if (this->getEnergy() <= 0)
	{
		std::cout << "> ClapTrap " << this->getName() << " Does not have enought energy" << std::endl;
		this->setEnergy(this->getEnergy() - 1);
		return ;
	}
	std::cout << "> ClapTrap " << this->getName() << " attacks " << target << " causing " << this->getDamage() << " points of damage!" << std::endl;
	this->setEnergy(this->getEnergy() - 1);
	std::cout << "---------- " << this->getName() << " End Attack -------------" << std::endl << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	this->setHit( this->getHit() - amount);
}