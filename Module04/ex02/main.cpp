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

int main()
{
	Animal *rafeiro = new Dog;
	Cat pantufa("Buzz");
	Dog bolinhas("Spock");

	rafeiro->getType();
	rafeiro->makeSound();
	
	pantufa.getType();
	pantufa.makeSound();

	bolinhas.getType();
	bolinhas.makeSound();

	delete rafeiro;
}
