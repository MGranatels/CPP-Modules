#include <Intern.hpp>

Intern::Intern() {
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern& Intern::operator=(const Intern& assign) {
	(void)assign;
    return *this;
}

Intern::Intern(Intern const &copy) {
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
	(void) copy;
}

Intern::~Intern() {
	std::cout << "\e[0;33mDefault Destructor called of Intern\e[0m" << std::endl;
}

AForm	*Intern::makeForm(std::string formName, std::string targetForm) {
	int		i = 0;
	AForm	*f1 = NULL;
	std::string form[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	while (i < 3 && form[i].compare(formName))
		i++;
	switch (i + 1) {
		case 1:
			std::cout << "PresidentialPardonForm Created!" << std::endl;
			f1 =  new PresidentialPardonForm(targetForm);
			break ;
		case 2:
			std::cout << "RobotomyRequestForm Created!" << std::endl;
			f1 =  new RobotomyRequestForm(targetForm);
			break ;
		case 3:
			std::cout << "ShrubberyCreationForm Created!" << std::endl;
			f1 =  new ShrubberyCreationForm(targetForm);
			break;
		default:
			throw Intern::FormNotFound();
	}
	return f1;
}

const char	*Intern::FormNotFound::what() const throw () {
	return "Intern caught exeption: \e[0;31m Form not found!\e[0m";
}