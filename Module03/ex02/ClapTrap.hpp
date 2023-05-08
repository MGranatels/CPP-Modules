/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:35:37 by mgranate          #+#    #+#             */
/*   Updated: 2023/04/29 19:42:21 by mgranate_ls      ###   ########.fr       */
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
	private:
		std::string	_name;
		int			_hit_Points;
		int			_energy_Points;
		int 		_attack_Damage;
		int			_last_attack;
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
		int		getLastAttack() const;

		void	setName( std::string const value );
		void	setHit( int const value );
		void	setDamage( int const value );
		void	setLastAttack(int const value);
		void	setEnergy( int const value );
		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

int		numberGenerator();

#endif