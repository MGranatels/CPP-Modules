#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>

class ShrubberyCreationForm {
public:
    int const _signGrade;
    int const _execGrade;

    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    // Member function declarations here
};

#endif // ShrubberyCreationForm_HPP
