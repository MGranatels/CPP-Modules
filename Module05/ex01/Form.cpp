#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(75), _execGrade(150)
{
	this->_isSigned = false;
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "\e[0;33mParametrizer Constructor called of Form\e[0m" << std::endl;
	this->_isSigned = false;
	if (signGrade < 1 || execGrade < 1)
		throw(Form::GradeTooHighException());
	else if (signGrade > 150 || execGrade > 150)
		throw(Form::GradeTooLowException());
}

Form & Form::operator=(const Form &assign)
{
	if (this->_signGrade <= assign.getSignGrade())
		this->_isSigned = assign.getIsGradeSign();
	else
		throw Form::GradeTooLowException();
	return *this;
}

Form::Form(const Form &copy) : _name(copy.getName()), _isSigned(false), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade())
{
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

Form::~Form() {
	std::cout << "\e[0;33mDestructer called of Form\e[0m" << std::endl;
    // Destructor code here
}

std::ostream &operator <<(std::ostream &out, Form &F)
{
	out << "------------------------------------------------" << std::endl;
	out << "\e[1;34mForm Name: \e[0m" << F.getName() << std::endl;
	out << "\e[1;34mSign Grade: \e[0m" << F.getSignGrade() << std::endl;
	out << "\e[1;34mExecute Grade: \e[0m" << F.getExecGrade() << std::endl;
	out << "\e[1;34mIs Grade Signed: \e[0m" << F.getIsGradeSign() << std::endl;
	out << "------------------------------------------------" << std::endl;
	return out;
}

std::string	Form::getName( void ) const {
	return this->_name;
}

int	Form::getSignGrade( void ) const {
	return this->_signGrade;
}

int	Form::getExecGrade( void ) const {
	return this->_execGrade;
}

bool	Form::getIsGradeSign( void ) const {
	return  this->_isSigned;
}

const char	*Form::GradeTooHighException::what() const throw() {
		return "\e[0;31mToo high to be signed!\e[0m";
}

const	char	*Form::GradeTooLowException::what() const throw() {
		return "\e[0;31mToo Low to be signed!\e[0m";
}

void	Form::beSigned(Bureaucrat& bureau) {
	if (bureau.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}
