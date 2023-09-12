/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:04:40 by bcarreir          #+#    #+#             */
/*   Updated: 2023/09/12 17:49:24 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Bin laden", 150);
		Form f("Anti-Terrorists", 32, 46);
		std::cout << a <<std::endl;
		std::cout << f << std::endl;
		a.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	try
	{
		Bureaucrat a("Hurry", 20);
		std::cout << a <<std::endl;
		Form f("Anti-Hurricanes", 18, 46);
		std::cout << f << std::endl;
		a.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	try
	{
		Bureaucrat a("Sht", 21);
		std::cout << a <<std::endl;
		a.incrementBur();
		Form f("Anti-Laxants", 22, 17);
		std::cout << f << std::endl;
		a.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
