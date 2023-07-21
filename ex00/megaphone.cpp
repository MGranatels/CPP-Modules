/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:43:19 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/03/21 22:00:05 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
 
void	capitalize(char *s)
{
	int	j;
	
	j = -1;
	while (s[++j])
		std::cout << (char)toupper(s[j]);
}

int	main (int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (av[++i])
		capitalize(av[i]);
	std::cout << std::endl;
}