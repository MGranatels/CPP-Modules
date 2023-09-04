#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>

class PresidentialPardonForm {
	private:
		int const _signGrade;
		int const _execGrade;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		
		//Setter and Getters
		int		getSignGrade( void ) const;
		int		getExecGrade( void ) const;
		// Member function declarations here
};

#endif // PresidentialPardonForm_HPP
