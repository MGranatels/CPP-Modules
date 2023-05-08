/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:32:14 by mgranate          #+#    #+#             */
/*   Updated: 2023/04/29 17:52:11 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	enemyTurn(ClapTrap &user, ClapTrap &enemy)
{
	int	_nb;

	_nb = numberGenerator();
	if (_nb % 2 == 0)
	{
		enemy.setDamage(numberGenerator());
		enemy.attack(user.getName());
		if (enemy.getEnergy() >= 0)
			user.setHit(user.getHit()  - enemy.getDamage());
	}
	else
		enemy.beRepaired(numberGenerator());
}

void	yourTurn(ClapTrap &user, ClapTrap &enemy)
{
	std::string	_actions;
	int	_pick = 0;
	
	std::cout << std::endl << "Choose one of the following actions:" << std::endl;
	std::cout << "1. Attack Enemy" << std::endl;
	std::cout << "2. Restore Health" << std::endl;
	std::cout << "> ";
	while (1)
	{
		std::getline(std::cin, _actions);
		_pick = std::atoi(_actions.c_str());
		if (_pick == 1 || _pick == 2 )
			break ;
		std::cout << "> Invalid Option, please try again: ";
	}
	switch(_pick){
		case 1:
			user.setDamage(numberGenerator());
			user.attack(enemy.getName());
			if (user.getEnergy() >= 0)
				enemy.setHit(enemy.getHit()  - user.getDamage());
		break;
		case 2:
			user.beRepaired(numberGenerator());
		break;
	}
}

int main( void ) {
	std::string _name;
    std::srand(std::time(0));

	std::cout << "> Set Your Character Name: ";
	std::getline(std::cin, _name);
	ClapTrap user(_name);
	ClapTrap enemy( user );
	std::cout << "> Set Enemy's Character Name: ";
	std::getline(std::cin, _name);
	enemy.setName(_name);
	std::cout << std::endl << "Let the battle commence, and may a legend rise from the ashes of the ones fallen dead!" << std::endl;
	while (checkDeath(user, enemy))
	{
		yourTurn(user, enemy);
		if (!checkDeath(user, enemy))
			break ;
		enemyTurn(user, enemy);
	}
	return (0);
}