#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Request", 145, 137), _target(target) {
	std::cout << "\e[0;33mParameter Constructor called of Shrubbery Form\e[0m" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& copy) {
    copy.setIsSign(this->getIsGradeSign());
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "\e[0;33mDefault Destructor called \e[0m" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!this->getIsGradeSign())
        throw ShrubberyCreationForm::NotSign();
    else if (executor.getGrade() > this->getExecGrade())
        throw ShrubberyCreationForm::GradeTooLowException();

    std::cout << this->getName() << " is designing an ASCII tree" << std::endl;
	std::ofstream outputFile;
	outputFile.open("trees.txt");
	if (!outputFile.is_open()) {
		std::cerr << "Error opening the file."	<< std::endl;
		return ;
	}
	outputFile << "    oxoxoo    ooxoo" << std::endl;
  	outputFile << "   ooxoxo oo  oxoxooo " << std::endl;
	outputFile << "  oooo xxoxoo ooo ooox " << std::endl;
 	outputFile << "  oxo o oxoxo  xoxxoxo " << std::endl;
	outputFile << "  oxo xooxoooo o ooooo " << std::endl;
   	outputFile << "      ooo\\oo\\  /o/o     " << std::endl;
    outputFile << "          \\  \\/ /"  << std::endl;
    outputFile << "           |   /      "  << std::endl;
    outputFile << "           |  |    "  << std::endl;
    outputFile << "           |  |    "  << std::endl;
    outputFile << "           |  |    "  << std::endl;
    outputFile << "           |  |    "  << std::endl;
  	outputFile << "    ______/____\\____ "  << std::endl;
    outputFile << std::endl;
    outputFile << "               ,@@@@@@@,"  << std::endl;
    outputFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o."  << std::endl;
    outputFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o"  << std::endl;
    outputFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'"  << std::endl;
    outputFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'"  << std::endl;
    outputFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'"  << std::endl;
    outputFile << "   `&%\\ ` /%&'    |.|        \\ '|8'"  << std::endl;
    outputFile << "       |o|        | |         | |"  << std::endl;
    outputFile << "       |.|        | |         | |"  << std::endl;
    outputFile << " \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_"  << std::endl;
    outputFile.close();
}

const char	*ShrubberyCreationForm::NotSign::what() const throw () {
	return "ShrubberyCreationForm Not signed";
}
