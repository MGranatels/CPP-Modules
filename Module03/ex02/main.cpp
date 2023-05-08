/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:32:14 by mgranate          #+#    #+#             */
/*   Updated: 2023/04/29 19:39:55 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	enemyTurn(ClapTrap &user, FragTrap &enemy)
{
	int	_nb;

	_nb = numberGenerator();
	if (_nb <= 3)
	{
		enemy.attack(user.getName());
		if (enemy.getEnergy() >= 0)
			user.setHit(user.getHit()  - enemy.getDamage());
	}
	else if (_nb <= 6)
		enemy.beRepaired(numberGenerator());
	else
		enemy.highFivesGuys();
}

void	yourTurn(ClapTrap &user, FragTrap &enemy)
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
	std::cout << "> Set Enemy's Character Name: ";
	std::getline(std::cin, _name);
	FragTrap enemy(_name);
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