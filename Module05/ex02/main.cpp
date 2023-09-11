/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:04:40 by bcarreir          #+#    #+#             */
/*   Updated: 2023/09/11 17:46:54 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try
	{
		Bureaucrat a("Bin laden", 20);
		Bureaucrat r("Sadam", 100);
		AForm *f1 =  new PresidentialPardonForm("home");
		a.signForm(*f1);
		f1->execute(a);
		f1->execute(r);
		std::cout << a << std::endl;
		std::cout << *f1 << std::endl;
		delete f1;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	try
	{
		Bureaucrat a("Bill Clinton", 20);
		Bureaucrat r("George w Bush", 100);
		AForm *f1 =  new ShrubberyCreationForm("Tree Writer");
		a.signForm(*f1);
		f1->execute(a);
		f1->execute(r);
		std::cout << a << std::endl;
		std::cout << *f1 << std::endl;
		delete f1;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	try
	{
		Bureaucrat a("Mr Robot", 20);
		Bureaucrat r("Mrs Robot", 50);
		AForm *f1 =  new RobotomyRequestForm("Robot Trainer");
		a.signForm(*f1);
		f1->execute(a);
		f1->execute(r);
		std::cout << a << std::endl;
		std::cout << *f1 << std::endl;
		delete f1;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}