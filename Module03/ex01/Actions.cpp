/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Actions.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:20:47 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/04/29 19:40:34 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	numberGenerator()
{
	int random_number;
	// Seed the random number generator with a random device
    
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
	std::cout << "You have Died, until your next live brave adventurer" << std::endl;
	return (0);
}

int	enemyDeath( void )
{	
	std::cout << std::endl << "Congratulations on your victory!" << std::endl;
	std::cout << "You have defeated a worthy opponent, but the road" << std::endl;
	std::cout << "to becoming the champion is still long. Keep training and" << std::endl;
	std::cout << "fighting to become the ultimate champion of the Arena of Champions!" << std::endl;
	return (0);
}

int	checkDeath(ClapTrap &user, ScavTrap &enemy)
{
	if (user.getHit() <= 0)
		return (userDeath());
	if (enemy.getHit() <= 0)
		return (enemyDeath());
	return (1);
}
