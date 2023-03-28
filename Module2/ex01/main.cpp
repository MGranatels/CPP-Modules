/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:41:12 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/03/27 16:17:41 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	get_number_zombies()
{
	std::string nr_zombies;
	int			nb;

	while (1)
	{
		std::cout << "> Enter number of Zombies in your horde: ";
		std::getline(std::cin, nr_zombies);
		nb = std::atoi(nr_zombies.c_str());
		if (nb <= 0)
			std::cout << "Invalid Input, please try again" << std::endl;
		else
			break;
	}
	return (nb);
}

int main( void ) {
	std::string *names;
	std::string	name;
	Zombie 		*zombiz;
	size_t		N;

	N = get_number_zombies();
	names = new std::string[N];
	for (size_t i = 0; i < N; i++)
	{
		std::cout << "> Enter Zombie Name nª" << i + 1 << ": ";
		std::getline(std::cin, names[i]);
		std::replace(names[i].begin(), names[i].end(), ' ', '_');
		name = name + names[i] + " ";
	}	
	std::cout << name << std::endl;
    zombiz = zombieHorde(N, name);
	for (size_t i = 0; i < N; i++){
		zombiz[i].announce();
	}
    delete [] zombiz;
	delete [] names;
    return 0;
}