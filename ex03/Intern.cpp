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

AForm *Intern::newShrubberyCreationForm(std::string traget)
{
    AForm* ptr;
    try 
    {
        ptr = new ShrubberyCreationForm(traget);
        throw std::bad_alloc();
    }
    catch(std::exception &e)
    {
        std::cout << "Error type: " << e.what() << std::endl;
    }
    return (ptr);
}

AForm *Intern::newRobotomyRequestForm(std::string traget)
{
    AForm* ptr;
    try 
    {
        ptr = new RobotomyRequestForm(traget);
        throw std::bad_alloc();
    }
    catch(std::exception &e)
    {
        std::cout << "Error type: " << e.what() << std::endl;
    }
    return (ptr);
}

AForm *Intern::newPresidentialPardonForm(std::string traget)
{
    AForm* ptr;
    try 
    {
        ptr = new PresidentialPardonForm(traget);
        throw std::bad_alloc();
    }
    catch(std::exception &e)
    {
        std::cout << "Error type: " << e.what() << std::endl;
    }
    return (ptr);
}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
    std::string forms_name[3] = {"ShrubberyCreationForm"
            , "RobotomyRequestForm", "PresidentialPardonForm"};

    AForm *(Intern::*f[])(std::string target) = 
    {
        &Intern::newShrubberyCreationForm, 
        &Intern::newRobotomyRequestForm, 
        &Intern::newPresidentialPardonForm,
    };
    for(int i = 0; i < 4 ; i++)
    {
        if (formName == forms_name[i])
        {
            return (this->*f[i])(target);
        }
    }
    throw "invalide name of formName";
    
}