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
        AForm *newShrubberyCreationForm(std::string traget);
        AForm *newRobotomyRequestForm(std::string traget);
        AForm *newPresidentialPardonForm(std::string traget);
        
};

#endif