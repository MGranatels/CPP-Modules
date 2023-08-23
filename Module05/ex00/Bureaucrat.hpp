#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
public:
    std::string	_name;
    int 		_grade;

    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Member function declarations here
	std::string	getName() const;
	int			getGrade() const;

	void		setName(std::string name);
	void		setGrade(int grade);

	void	incrementBur();
	void	decrementBur();
	class GradeTooLowException : public std::exception {
		public:
			virtual	const char* what()	const throw();
	};
	class GradeTooHighException : public std::exception {
		public:
			virtual	const char* what()	const throw();
	};
};


std::ostream &operator <<(std::ostream &out, const Bureaucrat &B);

#endif // Bureaucrat_HPP
