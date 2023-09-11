#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidencial Pardon", 25, 5), _target(target){
	std::cout << "\e[0;33mParameterConstructor called of Presidencial Form\e[0m" << std::endl;
}


PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &copy) {
    copy.setIsSign(this->getIsGradeSign());
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "\e[0;33mDefault Destructor called of \e[0m" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!this->getIsGradeSign())
        throw PresidentialPardonForm::NotSign();
    else if (executor.getGrade() > this->getExecGrade())
        throw PresidentialPardonForm::GradeTooLowException();
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const char	*PresidentialPardonForm::NotSign::what() const throw () {
	return "Presidential Form Not signed";
}