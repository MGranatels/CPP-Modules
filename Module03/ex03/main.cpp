/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:32:14 by mgranate          #+#    #+#             */
/*   Updated: 2023/05/01 13:40:44 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {
	std::string _name;

	std::cout << "> Set Enemy's Character Name: ";
	std::getline(std::cin, _name);
	DiamondTrap enemy(_name);
	std::cout << std::endl << "Check Values That were inherit" << std::endl;
	std::cout << "Hit Points: " << enemy.getHit() << " From FragTrap" << std::endl;
	std::cout << "Energy: " << enemy.getEnergy () << " From ScavTrap" << std::endl;
	std::cout << "Attack Damage: " << enemy.getDamage() << " From FragTrap" << std::endl;
	enemy.attack("Hidan");
	enemy.beRepaired (10);
	enemy.takeDamage (20);
	enemy.WhoAmI();
	return (0);
}