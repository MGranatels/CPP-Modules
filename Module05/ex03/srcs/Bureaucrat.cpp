#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(10) {
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}
Bureaucrat::Bureaucrat( std::string name, int	grade) : _name(name), _grade(grade) {
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
		return "Bureaucrat caught execption: \e[0;31mGrade Too high!";
}

const	char	*Bureaucrat::GradeTooLowException::what() const throw() {
		return "Bureaucrat caught execption: \e[0;31mGrade Too Low!";
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

void	Bureaucrat::signForm(AForm& F)
{
	try 
	{
		F.beSigned(*this);
		std::cout << "\e[0;32mBureaucrat \e[0m" << this->_name << " \e[0;32msigned " << F.getName() << " Form\e[0m" << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << this->_name << "\e[0;31m couldn't sign, " << F.getName() \
		<< " grade not high enough.\e[0m" << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << this->_name << "\e[0;31m couldn't execute " << form.getName() \
		<< " because his grade is not high enough.\e[0m" << std::endl;
	}
	catch (const AForm::FormNotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << this->_name << "\e[0;31m couldn't execute " << form.getName() \
		<< " because the form is not signed.\e[0m" << std::endl;
	}
}