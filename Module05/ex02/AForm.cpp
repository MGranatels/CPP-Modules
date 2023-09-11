#include "AForm.hpp"

AForm::AForm(void) : _name("Default"),
                     _signGrade(150),
                     _execGrade(150),
                     _isSigned(false) {
    // std::cout << "Called AForm default constructor" << std::endl;
}

AForm::AForm(std::string name, const int gradeRequired, const int gradeExec) : _name(name),
                                                                               _signGrade(gradeRequired),
                                                                               _execGrade(gradeExec),
                                                                               _isSigned(false) {
    if (gradeRequired > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
    else if (gradeRequired < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    std::cout << "Called AForm constructor with name and grade" << std::endl;
}
AForm & AForm::operator=(const AForm &assign)
{
	if (this->_signGrade <= assign.getSignGrade())
		this->_isSigned = assign.getIsGradeSign();
	else
		throw AForm::GradeTooLowException();
	return *this;
}

AForm::AForm(const AForm& copy) : _name(copy.getName()), 
								  _signGrade(copy.getSignGrade()), 
								  _execGrade(copy.getExecGrade()),
								  _isSigned(false) {
	std::cout << "\e[0;33mCopy Constructor called of AForm\e[0m" << std::endl;
}

AForm::~AForm() {
	std::cout << "\e[0;33mDestructer called of AForm\e[0m" << std::endl;
    // Destructor code here
}

std::ostream &operator <<(std::ostream &out, AForm &F)
{
	out << "From Name: " << F.getName() << std::endl;
	out << "Sign Grade: " << F.getSignGrade() << std::endl;
	out << "Execute Grade: " << F.getExecGrade() << std::endl;
	out << "Is Grade Signed: " << F.getIsGradeSign() << std::endl;

	return out;
}


std::string	AForm::getName( void ) const {
	return this->_name;
}

int	AForm::getSignGrade( void ) const {
	return this->_signGrade;
}

bool	AForm::getIsGradeSign( void ) const {
	return  this->_isSigned;
}

int	AForm::getExecGrade( void ) const {
	return this->_execGrade;
}

const char	*AForm::GradeTooHighException::what() const throw() {
		return "Grade Too high!";
}

const	char	*AForm::GradeTooLowException::what() const throw() {
		return "Grade Too Low!";
}

void	AForm::beSigned(Bureaucrat& bureau) {
	if (bureau.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
}
void	AForm::setIsSign(bool signMe) {
	this->_isSigned = signMe;
}
