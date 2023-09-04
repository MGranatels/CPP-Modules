#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _signGrade(145), _execGrade(137) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade() {
    // Copy constructor code here
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& assign) {
	if (this->_signGrade <= assign.getSignGrade())
		this->_isSigned = assign.getIsGradeSign();
	else
		throw Form::GradeTooLowException();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    // Destructor code here
}

int	RobotomyRequestForm::getSignGrade( void ) const {
	return this->_signGrade;
}

int	RobotomyRequestForm::getExecGrade( void ) const {
	return this->_execGrade;
}


const char	*RobotomyRequestForm::GradeTooHighException::what() const throw() {
		return "Grade Too high!";
}

const	char	*RobotomyRequestForm::GradeTooLowException::what() const throw() {
		return "Grade Too Low!";
}