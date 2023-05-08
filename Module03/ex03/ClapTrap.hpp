/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:35:37 by mgranate          #+#    #+#             */
/*   Updated: 2023/05/01 13:51:04 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstdlib>
# include <cstdlib>
# include <ctime>
# include <limits>

class ClapTrap {
	protected:
		std::string	_name;
		int			_hit_Points;
		int			_energy_Points;
		int 		_attack_Damage;
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap (const ClapTrap &point);
		ClapTrap& operator= (const ClapTrap& param);
		
		~ClapTrap( void );
		
		std::string	getName( void ) const;
		int		getDamage( void ) const;
		int		getHit( void ) const;
		int		getEnergy( void ) const;

		void	setName( std::string const value );
		void	setHit( int const value );
		void	setDamage( int const value );
		void	setEnergy( int const value );
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		virtual void	attack(const std::string& target);
};

int		numberGenerator();

#endif