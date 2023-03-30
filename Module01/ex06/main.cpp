/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:17:33 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/03/28 23:36:42 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl		h;
	std::string lvl;
	
	while (lvl != "EXIT")
	{
		std::cout << "> Enter Level of Emergency: ";
		std::getline(std::cin, lvl);
		h.complain(lvl);
	}
}