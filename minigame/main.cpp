/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:32:14 by mgranate          #+#    #+#             */
/*   Updated: 2023/04/24 18:16:29 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	callIntro(ClapTrap b)
{
	std::cout << "Hello " << b.getName() << " and Welcome to the Arena of Champions!" << std::endl;
	std::cout << "Here you will fight for glory, honor and to became the ultima Arena Champion!" << std::endl;
	std::cout << "Let's hope you are ready to embrace the challenge!";
	std::cout << std::endl << std::endl;
	std::cout << "You have made the bold decision to enter the Arena of Champions," << std::endl;
	std::cout << "where you will face off against legendary opponents whose names"<< std::endl;
	std::cout << "echo through the ages. Will you rise to the challenge and emerge victorious?" << std::endl;
	std::cout << "Only time will tell, but one thing is certain: the battles ahead will be epic and unforgiving." << std::endl; 
	std::cout << "Prepare yourself for a test of strength, skill, and willpower unlike any other," << std::endl;
	std::cout << "as you fight to claim your place among the greatest champions in history." <<std::endl;
	std::cout << std::endl << std::endl;
}

int	pickEnemy()
{
	std::string _enemy;
	int			_pick;
	
	std::cout << "The List of Champions ready to face you:" << std::endl;
	std::cout << "Level 1: Hermes,  The Messager Of God" << std::endl;
	std::cout << "Level 2: Afrodite,  The Goddess of Love" << std::endl;
	std::cout << "Level 3: Ares,  The God of War" << std::endl;
	std::cout << "Level 4: Zeus,  The God of gods" << std::endl << std::endl;
	std::cout << "> Pick Your Oponent: ";
	while (1)
	{
		std::getline(std::cin, _enemy);
		_pick = std::atoi(_enemy.c_str());
		if (_pick == 1 || _pick == 2 || _pick == 3 || _pick == 4)
			break ;
	}
	return (_pick);
}

void	enemyTurn(ClapTrap &user, ClapTrap &enemy)
{
	int	_nb;

	_nb = numberGenerator();
	if (_nb % 2 == 0)
		enemyAttack(enemy, user);
	else
		restoreAction(enemy);
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
			attackAction(user, enemy);
		break;
		case 2:
			restoreAction(user);
		break;
	}
	
}

int main( void ) {
	std::string _name;
	int			ctr;

	std::cout << "> Set Your Character Name: ";
	std::getline(std::cin, _name);
	ClapTrap a(_name);
	ClapTrap user( a );
	callIntro(user);
	while (1)
	{
		ctr = 1;
		ClapTrap* enemy = new ClapTrap(pickEnemy());
		std::cout << std::endl << "Let the battle commence, and may a legend rise from the ashes of the ones fallen dead!" << std::endl;
		while (ctr == 1)
		{
			ctr = checkDeath(user, *enemy);
			yourTurn(user, *enemy);
			ctr = checkDeath(user, *enemy);
			enemyTurn(user, *enemy);
		}
		if (ctr == 0)
		{
			delete enemy;
			break ;
		}
		user = a;
		delete enemy;
	}
	return (0);
}