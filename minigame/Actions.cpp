/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Actions.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:20:47 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/04/29 13:02:05 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	numberGenerator()
{
	int random_number;
	// Seed the random number generator with a random device
    std::srand(std::time(0));
    
    // Generate a random integer between 0 and 99
	while (1)
	{
		random_number = std::rand() % 100;
		if (random_number > 0 && random_number <= 10)
			break ;
	}
	return (random_number);
}
int	userDeath()
{
	std::string _input;
	std::cout << "You have Died, would you like to try again?" << std::endl;
	std::cout << "> Input Yes to try again: ";
	std::getline(std::cin, _input);
	if (_input == "Yes")
		return (2);
	return (0);
}

int	enemyDeath( void )
{
	std::string _input;
	
	std::cout << std::endl << "Congratulations on your victory!" << std::endl;
	std::cout << "You have defeated a worthy opponent, but the road" << std::endl;
	std::cout << "to becoming the champion is still long. Keep training and" << std::endl;
	std::cout << "fighting to become the ultimate champion of the Arena of Champions!" << std::endl;
	std::cout << "Would you like to fight another enemy?" << std::endl;
	std::cout << "> Input Yes to fight another battle: ";
	std::getline(std::cin, _input);
	if (_input == "Yes")
		return (2);
	return (0);
}

int	checkDeath(ClapTrap &user, ClapTrap &enemy)
{
	int	res = 1;
	
	if (user.getHit() <= 0)
	{
		std::cout << "DEBUG" << user.getHit() << std::endl;
		res = userDeath();
	}
	if (enemy.getHit() <= 0)
		res = enemyDeath();
	return (res);
}

void	enemyAttack(ClapTrap &enemy, ClapTrap &user)
{
	if (enemy.getEnergy() <= 0)
	{
		std::cout << "Not Enought Energy" << std::endl;
		return ;
	}
	std::cout << std::endl << "----------" << enemy.getName() << " Attacks ----------" << std::endl;
	std::cout << "> " << enemy.getName() << " attacks " << user.getName() << " causing " << enemy.getDamage() << " points of damage!" << std::endl;
	user.setHit(user.getHit() - enemy.getDamage());
	if (user.getHit() <= 0)
		user.setHit(0);
	std::cout << "> " << "You now have " << user.getHit() << " hp" << std::endl;
	user.setEnergy(enemy.getEnergy() - 1);
	std::cout << "----------" << enemy.getName() << " End Attack-------------" << std::endl;
}

/*void	victory(ClapTrap &user)
{
	std::cout << std::endl << "Congratulations, " << user.getName() << "! You have emerged" << std::endl; 
	std::cout << "victorious from the Arena of Champions, where only the strongest" << std::endl; 
	std::cout << "and most skilled warriors can claim glory. Your valor and determination" << std::endl;  
	std::cout << "have earned you the admiration of the crowd and the respect of your opponents." << std::endl; 
	std::cout << "Your name will forever be etched in the annals of the arena's history as a true Legend. " << std::endl; 
	std::cout << "Rest well tonight, for tomorrow, another battle awaits." << std::endl; 
}*/

void	attackAction (ClapTrap &user, ClapTrap &enemy)
{
	if (user.getEnergy() <= 0)
	{
		std::cout << "Not Enought Energy" << std::endl;
		return ;
	}
	std::string _dice;
	int			attack;
	std::cout << std::endl << "---------- " << user.getName() << " Attacks ----------" << std::endl;
	attack = numberGenerator();
	std::cout << "> " << user.getName() << " attacks " << enemy.getName() << " causing " << attack << " points of damage!" << std::endl;
	enemy.setHit(enemy.getHit() - attack);
	if (enemy.getHit() <= 0)
		enemy.setHit(0);	
	std::cout << "> "  << enemy.getName() << " Has now: " << enemy.getHit() << " HP points" << std::endl;
	user.setEnergy(user.getEnergy() - 1);
	std::cout << "---------- " << user.getName() << " End Attack -------------" << std::endl;
}

void	restoreAction (ClapTrap &user)
{
	int			_restore;

	std::cout << "Energy: " << user.getEnergy() << std::endl;
	if (user.getEnergy() <= 0)
	{
		std::cout << "Not Enought Energy" << std::endl;
		return ;
	}
	std::cout << std::endl << "------- "<< user.getName() << " RESTORE HEALTH -------" << std::endl;
	_restore = numberGenerator();
	user.setHit(user.getHit() + _restore);
	std::cout  << user.getName()  << " Restores " << _restore << "Hp" << std::endl;
	std::cout  << user.getName()  << " Now Has " << user.getDamage() << "Hp" << std::endl;
	user.setEnergy(user.getEnergy() - 1);
	std::cout << "---------- END RESTORE ACTION -------------" << std::endl;
}
