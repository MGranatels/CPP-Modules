/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:03:17 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/03/24 19:21:25 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	std::cout << "[Create Phonebook]" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << "[Destroy Phonebook]" << std::endl;
}

static	bool check_number(std::string s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return (!s.empty() && it == s.end());
}

void	Phonebook::add_contact(int i)
{
	std::cout << "First Name: ";
	std::getline (std::cin, Phonebook::list[i].first_name);
	std::cout << "Last Name: ";
	std::getline (std::cin, Phonebook::list[i].last_name);
	std::cout << "Nickname: ";
	std::getline (std::cin, Phonebook::list[i].nickname);
	while (1)
	{
		std::cout << "Phone Number: ";
		std::getline (std::cin, Phonebook::list[i].phone_number);
		if (!check_number(Phonebook::list[i].phone_number))
			std::cout << "Phone Number can only contain Numbers, try again!" << std::endl;
		else
			break ;
	}
	std::cout << "Secret: ";
	std::getline (std::cin, Phonebook::list[i].secret);
}
