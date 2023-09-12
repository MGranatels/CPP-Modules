#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45), _target(target){
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
	std::cout << "Making some drilling noises: Cling Plink" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
    int num = rand() % 2;
    if (!num)
        std::cout << this->getName() << " \e[0;32has been robotomized successfully\e[0m" << std::endl;
    else {
		std::cerr << this->getName() << "\e[0;31m robotomization failed." << std::endl;
		std::cerr << "Could not execute form\e[0m" << std::endl;
	}
    if (!this->getIsGradeSign())
        throw RobotomyRequestForm::NotSign();
    else if (executor.getGrade() > this->getExecGrade()) {
        throw RobotomyRequestForm::GradeTooLowException();
	}
}

const char	*RobotomyRequestForm::NotSign::what() const throw () {
	return "Robotomy caught exeption: \e[0;31mForm Not signed!\e[0m";
}