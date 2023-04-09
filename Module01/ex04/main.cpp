/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:16:14 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/03/28 20:39:59 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"


int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;	
		return (0);	
	}
	Replace rep(av[3], av[2], av[1]);
	rep.read_file();
}