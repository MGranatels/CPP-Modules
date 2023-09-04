#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>

class PresidentialPardonForm {
public:
    int const _signGrade;
    int const _execGrade;

    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    // Member function declarations here
};

#endif // PresidentialPardonForm_HPP
