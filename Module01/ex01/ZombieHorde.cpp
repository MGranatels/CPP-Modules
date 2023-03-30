/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:16:11 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/03/27 15:15:48 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cctype>

int	len(std::string s, int start)
{
	int	i;
	
	i = 0;
	while (!isspace(s[start]))
	{
		i++;
		start++;
	}
	return (i);
}

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *Horde = new Zombie[N];
	int		start;

	start = 0;
	for (int i = 0; i < N; i++)
	{
		Horde[i].setName(name.substr(start, len(name, start)));
		start += len(name, start) + 1;
	}
	return (Horde);
}