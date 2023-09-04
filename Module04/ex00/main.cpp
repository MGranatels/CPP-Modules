/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:48:29 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/05/07 15:56:08 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal *h = new WrongCat();


Cat meow ("Golden Cat");
Cat grwal( meow );

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << "I should be a cat but I am actually a: " << h->getType() << std::endl;
//grwal.makeSound();
meow.makeSound();
std::cout << "Grwal and Meow Should be the same type: " << grwal.getType() << " " << std::endl;
std::cout << "Grwal and Meow Should be the same type: " << meow.getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound(); //will output the dog sound!
h->makeSound(); //will output the dog sound beacause im a wrong cat!
meta->makeSound();
std::cout << meta->getType() << " " << std::endl;

delete j;
delete i;
delete meta;
delete h;

return 0;
}
