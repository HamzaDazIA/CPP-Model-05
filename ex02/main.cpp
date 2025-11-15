#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(NULL));

    std::cout << "\033[33m" << std::endl << "=== Test ShrubberyCreationForm ===" << "\033[0m" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrub("Garden");
        
        std::cout << bob << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\033[33m" << std::endl << "=== Test RobotomyRequestForm ===" << "\033[0m" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 45);
        RobotomyRequestForm robot("Bender");
        
        std::cout << alice << std::endl;
        alice.signForm(robot);
        alice.executeForm(robot);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\033[33m" << std::endl << "=== Test PresidentialPardonForm ===" << "\033[0m" << std::endl;
    try
    {
        Bureaucrat president("President", 5);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << president << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\033[33m" << std::endl << "=== Test Grade Too Low to Sign ===" << "\033[0m" << std::endl;
    try
    {
        Bureaucrat lowGrade("LowGrade", 150);
        PresidentialPardonForm pardon2("Ford Prefect");
        
        lowGrade.signForm(pardon2);
        lowGrade.executeForm(pardon2);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\033[33m" << std::endl << "=== Test Grade Too Low to Execute ===" << "\033[0m" << std::endl;
    try
    {
        Bureaucrat signer("Signer", 25);
        Bureaucrat executor("Executor", 50);
        PresidentialPardonForm pardon3("Zaphod");
        
        signer.signForm(pardon3);
        executor.executeForm(pardon3);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\033[33m" << std::endl << "=== Test Execute Unsigned Form ===" << "\033[0m" << std::endl;
    try
    {
        Bureaucrat exec("Exec", 1);
        ShrubberyCreationForm unsignedForm("Home");
        
        exec.executeForm(unsignedForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}