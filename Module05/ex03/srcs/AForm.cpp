#include "../includes/AForm.hpp"

AForm::AForm(void) : _name("Default"),
                     _signGrade(150),
                     _execGrade(150),
                     _isSigned(false) {
    std::cout << "\e[0;33mDefault Constructor called of Form\e[0m " << _name << std::endl;
}

AForm::AForm(std::string name, const int gradeRequired, const int gradeExec) : _name(name),
                                                                               _signGrade(gradeRequired),
                                                                               _execGrade(gradeExec),
                                                                               _isSigned(false) {
    if (gradeRequired > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
    else if (gradeRequired < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    std::cout << "\e[0;33mParameter Constructor called of Form\e[0m " << _name << std::endl;
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
}

std::ostream &operator <<(std::ostream &out, AForm &F)
{
	out << "------------------------------------------------" << std::endl;
	out << "\e[1;34mForm Name: \e[0m" << F.getName() << std::endl;
	out << "\e[1;34mSign Grade: \e[0m" << F.getSignGrade() << std::endl;
	out << "\e[1;34mExecute Grade: \e[0m" << F.getExecGrade() << std::endl;
	out << "\e[1;34mIs Grade Signed: \e[0m" << F.getIsGradeSign() << std::endl;
	out << "------------------------------------------------" << std::endl;
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
		return "AForm caught exeption: \e[0;31mGrade Out of Bounds Too High!\e[0m";
}

const	char	*AForm::GradeTooLowException::what() const throw() {
		return "AForm caught exeption: \e[0;31mGrade Too Low!\e[0m";
}

const	char	*AForm::FormNotSignedException::what() const throw() {
		return "AForm caught exeption: \e[0;31mForm Not Signed!\e[0m";
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
