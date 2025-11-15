#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &obj);
        ~Intern();
        Intern &operator=(const Intern &obj);
        AForm *makeForm(const std::string formName, const std::string target);
        AForm *newShrubberyCreationForm(std::string target);
        AForm *newRobotomyRequestForm(std::string target);
        AForm *newPresidentialPardonForm(std::string target);
        
};

#endif