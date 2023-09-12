#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string _target;
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(PresidentialPardonForm& copy);
		~PresidentialPardonForm();
		
		// Member function declarations here
		void	execute(Bureaucrat const &executor) const;
		class NotSign : public std::exception {
			public:
				virtual	const char* what()	const throw();
		};
};

#endif // PresidentialPardonForm_HPP
