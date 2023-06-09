/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:41:12 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/04/10 21:13:33 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	std::string wepon;
	std::string input;
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	HumanB jim("Jim");
	while (bob.check_hp() > 0 && jim.check_hp() > 0)
	{
		std::getline (std::cin, input);
		club.setType("Long Sword");
		jim.setWeapon(club);
		
	}
	bob.attack();
	bob.attack();
	
	jim.attack();
	club.setType("Axe");
	jim.attack();
	return 0;
}