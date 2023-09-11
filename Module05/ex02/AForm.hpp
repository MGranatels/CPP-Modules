#ifndef AForm_HPP
#define AForm_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string _name;
		int			_signGrade;
		int			_execGrade;
		bool		_isSigned;
	public:

		//Constructers and Destructers
		AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		AForm(std::string name, int signGrade, int execGrade);
		virtual ~AForm();

		//Setter and Getters
		std::string	getName( void ) const;
		bool	getIsGradeSign( void ) const;
		int		getSignGrade( void ) const;
		int		getExecGrade( void ) const;
		void	setIsSign (bool signMe);

		//Member Functions
		void	beSigned(Bureaucrat& bureau);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooLowException : public std::exception {
			public:
				virtual	const char* what()	const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual	const char* what()	const throw();
		};
};

std::ostream & operator<<(std::ostream &out, AForm &F);

#endif // AForm_HPP
