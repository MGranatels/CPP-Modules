/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:35:37 by mgranate          #+#    #+#             */
/*   Updated: 2023/04/22 14:25:46 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__
#include <iostream>
#include <math.h>
#include <string>
#include <cmath>

class Fixed {
	public:
		Fixed( void );
		Fixed(const Fixed&);
		Fixed(const int num);
		Fixed(const float num);
		Fixed&	operator= (const Fixed&);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
		bool operator > (Fixed const &value);
		bool operator < (Fixed const &value);
		bool operator >= (Fixed const &value);
		bool operator <= (Fixed const &value);
		bool operator == (Fixed const &value);
		bool operator != (Fixed const &value);
		Fixed operator + (Fixed const &value);
		Fixed operator - (Fixed const &value);
		Fixed operator * (Fixed const &value);
		Fixed operator / (Fixed const &value);
		Fixed operator ++();
		Fixed operator ++(int);
		Fixed operator --(int);
		Fixed operator --();
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
	private:
		int _fixedNum;
		const static int _fractional_bits = 8;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif