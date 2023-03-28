/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:43:48 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/03/27 20:44:19 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
 	std::string _name;
    Weapon*     _weapon;

public:
    HumanB( std::string name );
    ~HumanB();

    void    attack( void ) const;
    void    setWeapon( Weapon& weapon );
};

#endif