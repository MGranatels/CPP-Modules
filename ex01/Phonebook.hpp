
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

class Phonebook {

public:
	Phonebook(void);
	~Phonebook(void);
	Contact list[8];
	void	add_contact(int i);
};

#endif