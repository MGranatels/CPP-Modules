/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:44:35 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/05/07 22:12:11 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal {
private:
	Brain *_brain;

public:

    Cat();
    Cat(const Cat& other);
	Cat(std::string name);
    Cat& operator=(const Cat& other);
    ~Cat();

	virtual void	makeSound() const;
	virtual std::string	getType( void ) const;
	void	getIdeas( void ) const;
};

#endif 
