#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) :  _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade()) {
    // Copy constructor code here
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& assign) {
	if (this->_signGrade <= assign.getSignGrade())
		this->_isSigned = assign.getIsGradeSign();
	else
		throw Form::GradeTooLowException();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    // Destructor code here
}

int	Form::getExecGrade( void ) const {
	return this->_execGrade;
}

bool	Form::getIsGradeSign( void ) const {
	return  this->_isSigned;
}
