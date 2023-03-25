
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

class Phonebook {
private:
	void	check_contact_list();
	static int	_ind;
	static int	nb_cont;
	Contact list[8];

public:

	Phonebook(void);
	~Phonebook(void);

	void	add();
	void	search();
};

#endif