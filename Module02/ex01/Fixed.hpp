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

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed {
	private:
		int	_fixedPoint;
		static const int _bit = 8;
	public:
		Fixed( void );
		Fixed (const Fixed &point);
		Fixed( const int _nb );
		Fixed (const float _nb);
		Fixed& operator=(const Fixed &point);
		~Fixed( void );
		
		int		getRawBits( void ) const;
		int		toInt( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
};

#endif