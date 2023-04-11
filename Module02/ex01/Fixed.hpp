/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FIxed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:35:37 by mgranate          #+#    #+#             */
/*   Updated: 2023/03/30 16:57:59 by mgranate         ###   ########.fr       */
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
		Fixed();
		Fixed(const Fixed&);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed&	operator= (const Fixed&); // const for safety... not super nesessary
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int _fixedNum;
		const static int _fractional_bits = 8;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);



#endif