#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include <string>
# include <PresidentialPardonForm.hpp>
# include <ShrubberyCreationForm.hpp>
# include <RobotomyRequestForm.hpp>

class Intern {
public:

    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
	class FormNotFound : public std::exception {
		public:
			virtual	const char* what()	const throw();
	};
    // Member function declarations here
	AForm	*makeForm(std::string formName, std::string targetForm);
};

#endif // Intern_HPP
