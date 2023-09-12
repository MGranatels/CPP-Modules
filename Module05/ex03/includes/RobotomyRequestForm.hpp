#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>  
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		const std::string _target;
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(RobotomyRequestForm& copy);
		~RobotomyRequestForm();
		void	execute(Bureaucrat const &executor) const;
		class NotSign : public std::exception {
		public:
			virtual	const char* what()	const throw();
		};
};

#endif // RobotomyRequestForm_HPP
