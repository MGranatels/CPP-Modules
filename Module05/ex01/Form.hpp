#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const	_name;
		bool				_isSigned;
		int	const			_signGrade;
		int	const			_execGrade;

	public:

		//Constructers and Destructers
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		Form(std::string name, int signGrade, int execGrade);
		~Form();

		//Setter and Getters
		std::string	getName( void ) const;
		bool	getIsGradeSign( void ) const;
		int		getSignGrade( void ) const;
		int		getExecGrade( void ) const;

		//Member Functions
		void	beSigned(Bureaucrat& bureau);
		class GradeTooLowException : public std::exception {
			public:
				virtual	const char* what()	const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual	const char* what()	const throw();
		};
};

std::ostream & operator<<(std::ostream &out, Form &F);

#endif // Form_HPP
