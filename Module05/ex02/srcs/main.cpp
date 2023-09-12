/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:04:40 by bcarreir          #+#    #+#             */
/*   Updated: 2023/09/12 02:09:05 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <PresidentialPardonForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <"RobotomyRequestForm.hpp>

int main()
{
	AForm *f1 =  new PresidentialPardonForm("Terrorist");
	AForm *f2 =  new ShrubberyCreationForm("Politic");
	AForm *f3 =  new RobotomyRequestForm("Robot Trainer");
	AForm *f4 =  new RobotomyRequestForm("Robot Meta");
	AForm *f5 =  new ShrubberyCreationForm("Ascii Boss");
	AForm *f6 =  new PresidentialPardonForm("Naziss");
	
	try
	{
		std::cout << *f1 << std::endl;
		Bureaucrat a("Bin laden", 5);
		std::cout << a << std::endl;
		a.signForm(*f1);
		f1->execute(a);
		std::cout << *f1 << std::endl;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "-------------------------------------" << std::endl;
	try
	{
		std::cout << *f2 << std::endl;
		Bureaucrat a("Bill Clinton", 20);
		std::cout << a << std::endl;
		a.signForm(*f2);
		f2->execute(a);
		std::cout << *f2 << std::endl;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "------------------------------------------------" << std::endl;
	try
	{
		std::cout << *f3 << std::endl;
		Bureaucrat a("Mr Robot", 15);
		std::cout << a << std::endl;
		a.signForm(*f3);
		f3->execute(a);
		std::cout << *f3 << std::endl;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "-------------------------------------" << std::endl;
	try 
	{
		std::cout << *f4 << std::endl;
		Bureaucrat a("Mr Tree", 20);
		std::cout << a << std::endl;
		a.signForm(*f4);
		f4->execute(a);
		std::cout << *f4 << std::endl;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
	}
		try 
	{
		std::cout << *f5 << std::endl;
		Bureaucrat a("Ascii Prodigy", 1);
		std::cout << a << std::endl;
		a.signForm(*f5);
		f5->execute(a);
		std::cout << *f5 << std::endl;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
	}
	try 
	{
		std::cout << *f6 << std::endl;
		Bureaucrat a("Hitler", 1);
		std::cout << a << std::endl;
		a.signForm(*f6);
		f6->execute(a);
		std::cout << *f6 << std::endl;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
	}
	delete f1;
	delete f2;
	delete f3;
	delete f4;
	delete f5;
	delete f6;
	return 0;
}