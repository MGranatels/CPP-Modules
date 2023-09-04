/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:33:04 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/09/04 09:42:36 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main ( void ) 
{
	try { Bureaucrat letsTry("TooLow", 151);	
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	
	
	try { Bureaucrat letsTry("TooHigh", 0);	
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	
	try { 
		Bureaucrat letsTry("Increment_One", 1);
		std::cout << "Lets Try and Increment 1!" << std::endl;
		letsTry.incrementBur();
		std::cout << letsTry;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}


	try { 
		Bureaucrat letsTry("Decrement_One", 150);
		std::cout << "Lets Try and Decrement 150!" << std::endl;
		letsTry.incrementBur();
		std::cout << letsTry;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	try { 
		Bureaucrat letsTry("Increment_One", 56);
		std::cout << "Lets Try and Increment 1!" << std::endl;
		letsTry.incrementBur();
		std::cout << letsTry;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	try { 
		Bureaucrat letsTry("Decrement_One", 56);
		std::cout << "Lets Try and Increment 1!" << std::endl;
		letsTry.incrementBur();
		std::cout << letsTry;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}