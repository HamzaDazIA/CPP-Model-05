#ifndef ShrubberyCreationForm_HPP   
#define ShrubberyCreationForm_HPP   

#include "Bureaucrat.hpp"
#include <fstream>
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    void execute(Bureaucrat const & executor) const;

    class FaileOpenException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};

#endif