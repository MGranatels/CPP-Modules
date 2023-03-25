/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:03:17 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/03/25 00:01:31 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <cstdlib>

Phonebook::Phonebook()
{
	std::cout << "[Create Phonebook]" << std::endl;
}

int	Phonebook::_ind = 0;
int	Phonebook::nb_cont = 0;

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

static int	check_contact(std::string s, int i)
{
	if (s.empty())
	{
		std::cout << " No input found, please try again! " << std::endl;
		return (0);
	}
	(void) i;
	if (i == 3)
	{
		if (!check_number(s))
		{
			std::cout << " Phone Number can only contain Numbers, try again! " << std::endl;
			return (0);
		}
		if (s.length() != 9)
		{
			std::cout << " Phone Number needs to contain 9 digits! " << std::endl;
			return(0);
		}
	}
	return (1);
}

void	Phonebook::add()
{
	int			j;

	j = 0;
	while (j != 5)
	{		
		if (j == 0)
		{
			std::cout << "> First Name: ";
			std::getline (std::cin, this->list[this->_ind].first_name);
			if (check_contact(this->list[this->_ind].first_name, j))
				j++;
		}
		if (j == 1)
		{
			std::cout << "> Last Name: ";
			std::getline (std::cin, this->list[this->_ind].last_name);
			if (check_contact(this->list[this->_ind].last_name, j))
				j++;
		}
		if (j == 2)
		{
			std::cout << "> Nickname: ";
			std::getline (std::cin, this->list[this->_ind].nickname);
			if (check_contact(this->list[this->_ind].nickname, j))
				j++;
		}
		if (j == 3)
		{
			std::cout << "> Phone Number: ";
			std::getline (std::cin, this->list[this->_ind].phone_number);
			if (check_contact(this->list[this->_ind].phone_number, j))
				j++;
		}
		if (j == 4)
		{
			std::cout << "> Secret: ";
			std::getline (std::cin, this->list[this->_ind].secret);
			if (check_contact(this->list[this->_ind].secret, j))
				j++;
		}
	}
	if (this->_ind == 7)
		this->_ind = 0;
	else
		this->_ind++;
	if (this->nb_cont != 7)
		this->nb_cont++;
}

static	void print_contacts(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (i > 8)
		{
			std::cout << ".";
			break ;
		}
		std::cout << str[i];
	}
}

void Phonebook::check_contact_list()
{
	std::string	input;
	int			ind;	

	while (1)
	{
		std::getline (std::cin, input);
		ind = std::atoi(input.c_str());
		ind--;
		if (check_number(input))
			if (ind <= this->nb_cont && ind >= 0)
			{
				std::cout << std::endl << "_____________Contact Details_____________" << std::endl;
				std::cout << "> First Name: " << this->list[ind].first_name << std::endl;
				std::cout << "> Last Name: " << this->list[ind].last_name << std::endl;
				std::cout << "> Nickname: " << this->list[ind].nickname << std::endl;
				std::cout << "> Phone Number: " << this->list[ind].phone_number << std::endl;
				std::cout << "> Secret: " << this->list[ind].secret << std::endl;
				std::cout << "- - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;
				break ;
			}
		std::cout << "Invalid Input, Please try Again: ";
	}		
}

void	Phonebook::search()
{
	int			i;
	std::string input;

	i = 0;
	std::cout << std::endl << "_______________ Contacts _______________" << std::endl << std::endl;
	while (i < 8 && !this->list[i].first_name.empty())
	{
		std::cout << i + 1 << " | ";
		print_contacts(this->list[i].first_name);
		std::cout <<  " | ";
		print_contacts(this->list[i].last_name);
		std::cout <<  " | ";
		print_contacts(this->list[i].nickname);
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl << "- - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;
	std::cout << "> Select Your Contact: ";
	check_contact_list();
}
