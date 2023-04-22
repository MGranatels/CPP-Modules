/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:32:14 by mgranate          #+#    #+#             */
/*   Updated: 2023/04/22 16:20:45 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a = 20;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed const c( Fixed( 10.76f ) / Fixed( 2 ) );
Fixed const d( Fixed( 25.98f ) - Fixed( 2 ) );
Fixed const e( Fixed( 10.76f ) + Fixed( 2 ) );


std::cout << "Comparison Operators: " << std::endl;
if (a > b)
	std::cout << "A = "<< a <<" is Bigger than B = " << b << std::endl;
if (a >= 20)
	std::cout << "A = "<< a <<" is equal to " << 20 << std::endl;
if (a < d)
	std::cout << "A = "<< a <<" is smaller than D = " << d << std::endl;
if (a <= 20)
	std::cout << "A = "<< a <<" is equal to: " << 20 << std::endl;
if (a != e)
	std::cout << "A = "<< a <<" is different than E= " << e << std::endl;
if (a == 20)
	std::cout << "A = "<< a <<" is equal to: " << 20 << std::endl << std::endl;

std::cout << "Arithmetic Operators: " << std::endl;
std::cout << "Multiplication: B is equal to: " << b << std::endl;
std::cout << "Division: C is equal to: " << c << std::endl;
std::cout << "Subtraction: d is equal to: " << d << std::endl;
std::cout << "Addition: e is equal to: " << e << std::endl << std::endl;

std::cout << "Increment Operators: " << std::endl;
std::cout << "Original Value of a = " << a << std::endl;
std::cout << "Incrementing before: " << ++a << "=> Has you can see A changed before printing" << std::endl;
std::cout << "Incrementing after: " << a++ << "=> Has you can see A has not changed before printing" << std::endl;
std::cout << "But if you check now it's value has change: " << a << std::endl;
std::cout << "Decrementing before: " << --a << "=> Has you can see A changed before printing" << std::endl;
std::cout << "Decrementing after: " << a-- << "=> Has you can see A has not changed before printing" << std::endl;
std::cout << "But if you check now it's value has change: " << a << std::endl << std::endl;

std::cout << "Min and Max Operators: " << std::endl;
std::cout << "The smallest value is gonna be B: " << Fixed::min( d, b ) << std::endl;
std::cout << "The smallest value is gonna be 8: " << Fixed::min( a, 8 ) << std::endl;
std::cout << "The Hights value is gonna be D: " << Fixed::max( d, b ) << std::endl;
std::cout << "The Highest value is gonna be a: " << Fixed::max( a, 8 ) << std::endl;

return 0;
}
