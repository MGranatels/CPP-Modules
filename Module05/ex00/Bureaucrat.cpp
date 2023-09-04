#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(10) {
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}
Bureaucrat::Bureaucrat( std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "\e[0;33mParameter Constructor called of Bureaucrat \e[0m" << this->_name << std::endl;
	if (this->_grade > 150)
		throw GradeTooLowException();
	else if (this->_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()), _grade(copy.getGrade()) {
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << this->_name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& assign) {
    this->_grade = assign.getGrade();  
    return *this;
}


Bureaucrat::~Bureaucrat() {
    // Destructor code here
}

std::string	Bureaucrat::getName() const { 
	return (this->_name);
}

void	Bureaucrat::setName(std::string name) {
	this->_name = name;
}


int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade) {
	this->_grade = grade;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
		return "Grade Too high!";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
		return "Grade Too Low!";
}

void	Bureaucrat::incrementBur() {
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade--;
} 

void	Bureaucrat::decrementBur() {
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::ostream &operator <<(std::ostream &out, const Bureaucrat &B)
{
	out << B.getName() << ", Bureaucrat grade " << B.getGrade() << "." << std::endl;
	return out;
}
