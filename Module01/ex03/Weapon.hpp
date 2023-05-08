/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:43:27 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/04/10 20:54:32 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

private:
	std::string _type;

public:

    Weapon(std::string type);
    ~Weapon();
	int		weapon_damage( int value );
	const	std::string getType( void );
	void	setType( std::string newType );
};

#endif