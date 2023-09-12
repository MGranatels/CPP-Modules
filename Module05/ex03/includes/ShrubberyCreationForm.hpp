#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const std::string _target;
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();
		void	execute(Bureaucrat const &executor) const;
		class NotSign : public std::exception {
		public:
			virtual	const char* what()	const throw();
		};
    // Member function declarations here
};

#endif // ShrubberyCreationForm_HPP
