#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(NULL));
    
    Intern someRandomIntern;
    AForm* form1;
    AForm* form2;
    AForm* form3;
    AForm* form4;

    std::cout << "\033[33m" << std::endl << "=== Test 1: Create Shrubbery Form ===" << "\033[0m" << std::endl;
    form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (form1)
    {
        Bureaucrat bob("Bob", 137);
        bob.signForm(*form1);
        bob.executeForm(*form1);
        delete form1;
    }

    std::cout << "\033[33m" << std::endl << "=== Test 2: Create Robotomy Form ===" << "\033[0m" << std::endl;
    form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form2)
    {
        Bureaucrat alice("Alice", 45);
        alice.signForm(*form2);
        alice.executeForm(*form2);
        delete form2;
    }

    std::cout << "\033[33m" << std::endl << "=== Test 3: Create Presidential Pardon Form ===" << "\033[0m" << std::endl;
    form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (form3)
    {
        Bureaucrat president("President", 5);
        president.signForm(*form3);
        president.executeForm(*form3);
        delete form3;
    }

    std::cout << "\033[33m" << std::endl << "=== Test 4: Invalid Form Name ===" << "\033[0m" << std::endl;
    form4 = someRandomIntern.makeForm("invalid form", "Target");
    if (form4)
    {
        delete form4;
    }
    else
    {
        std::cout << "Form creation failed as expected" << std::endl;
    }

    return 0;
}