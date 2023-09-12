#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 25, 5), _target(target) {
	std::cout << "\e[0;33mParameter Constructor called of Presidencial Form\e[0m " << _target << std::endl;
}


PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &copy) {
    copy.setIsSign(this->getIsGradeSign());
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy), _target(copy._target) {
	std::cout << "\e[0;33mCopy Constructor called of PresidentialPardon\e[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "\e[0;33mDefault Destructor called of PResidentialPardon\e[0m" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!this->getIsGradeSign())
        throw PresidentialPardonForm::NotSign();
    else if (executor.getGrade() > this->getExecGrade())
        throw PresidentialPardonForm::GradeTooLowException();
    std::cout << this->getName() << "\e[0;32m has been pardoned by Zaphod Beeblebrox\e[0m" << std::endl;
}

const char	*PresidentialPardonForm::NotSign::what() const throw () {
	return "PresidentialPardonForm caught exeption: \e[0;31m This form was not signed!.\e[0m";
}