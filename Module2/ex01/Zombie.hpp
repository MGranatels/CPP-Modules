/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:39:11 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/03/27 15:29:25 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <algorithm>

class Zombie
{
private:
    std::string _name;

public:
    Zombie();
    ~Zombie();
    void    announce( void );
    Zombie* newZombie( std::string name );
    void    setName( std::string name );
	Zombie *Horde;
};

Zombie*    zombieHorde( int N, std::string name );

#endif // ZOMBIE_HPP