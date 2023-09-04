#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>

class RobotomyRequestForm {
public:
    int const _signGrade;
    int const _execGrade;

    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
	int	getSignGrade() const;
	int	getExecGrade() const;
	class GradeTooLowException : public std::exception {
		public:
			virtual	const char* what()	const throw();
	};
	class GradeTooHighException : public std::exception {
		public:
			virtual	const char* what()	const throw();
	};
};

#endif // RobotomyRequestForm_HPP
