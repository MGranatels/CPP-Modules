#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 72, 45), _target(target){
	std::cout << "\e[0;33mParameterConstructor called of Presidencial Form\e[0m" << std::endl;
}


RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &copy) {
    copy.setIsSign(this->getIsGradeSign());
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "\e[0;33mDefault Destructor called of \e[0m" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!this->getIsGradeSign())
        throw RobotomyRequestForm::NotSign();
    else if (executor.getGrade() > this->getExecGrade()) {
        throw RobotomyRequestForm::GradeTooLowException();
	}
	std::cout << "Making some drilling noises: Cling Plink" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
    int num = rand() % 2;
    if (!num)
        std::cout << this->getName() << " has been robotomized successfully" << std::endl;
    else
        std::cerr << this->getName() << " robotomization failed." << std::endl;
}

const char	*RobotomyRequestForm::NotSign::what() const throw () {
	return "Robot Form Not signed";
}