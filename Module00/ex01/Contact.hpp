#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact {
	
private:

public:
	Contact(void);
	~Contact(void);

	std::string first_name;
	std::string last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;
};

#endif