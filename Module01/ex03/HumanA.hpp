/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:44:21 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/03/27 20:44:46 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

private:
	std::string _name;
	Weapon&		_weapon;
	HumanA();

public:

    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
	void	attack( void ) const;

    // Member function declarations here
};

#endif