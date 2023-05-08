/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:48:29 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/05/07 22:26:23 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	unsigned int n = 100;
	Animal *horde[n];

	for (unsigned int i = 0; i < n; i++)
		i < n/2 ? horde[i] = new Cat() : horde[i] = new Dog();
	for (unsigned int i = 0; i < n; i++)
		horde[i]->makeSound();
	for (unsigned int i = 0; i < n; i++)
		delete horde[i];
}