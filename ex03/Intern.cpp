#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &obj)
{
    (void)obj;
}
Intern::~Intern() {}

Intern &Intern::operator=(const Intern &obj)
{
    (void)obj;
    return (*this);
}

AForm *Intern::newShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::newRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::newPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
    std::string forms_name[3] = {"shrubbery creation",
            "robotomy request", "presidential pardon"};

    AForm *(Intern::*f[])(std::string target) = 
    {
        &Intern::newShrubberyCreationForm, 
        &Intern::newRobotomyRequestForm, 
        &Intern::newPresidentialPardonForm,
    };
    for(int i = 0; i < 3; i++)
    {
        if (formName == forms_name[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*f[i])(target);
        }
    }
    std::cout << "Error: Form name '" << formName << "' is not valid" << std::endl;
    return NULL;
}