/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:04:40 by bcarreir          #+#    #+#             */
/*   Updated: 2023/09/12 11:11:13 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Intern.hpp>

int main()
{
	AForm* f1;
	AForm* f2;
	AForm* f3;
	AForm* f4;
	
	try 
	{
		Intern someRandomIntern;
		Bureaucrat a("George W Bush", 5);
		f1 = someRandomIntern.makeForm("PresidentialPardonForm", "President");
		std::cout << *f1 << std::endl;
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
		Intern someRandomIntern;
		Bureaucrat a("Creationist", 5);
		f2 = someRandomIntern.makeForm("ShrubberyCreationForm", "Tree of Life");
		std::cout << *f2 << std::endl;
		a.signForm(*f2);
		f2->execute(a);
		std::cout << *f2 << std::endl;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "-------------------------------------" << std::endl;
	try 
	{
		Intern someRandomIntern;
		Bureaucrat a("RoboCop", 41);
		f3 = someRandomIntern.makeForm("RobotomyRequestForm", "Robotomation");
		std::cout << *f3 << std::endl;
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
		Intern someRandomIntern;
		Bureaucrat a("Non Existing Form", 41);
		f4 = someRandomIntern.makeForm("Non Existing Form", "Bender");
		std::cout << *f4 << std::endl;
		a.signForm(*f4);
		f4->execute(a);
		std::cout << *f4 << std::endl;
	}
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	delete f1;
	delete f2;
	delete f3;
	return 0;
}