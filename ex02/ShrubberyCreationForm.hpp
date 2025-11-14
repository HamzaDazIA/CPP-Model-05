#ifndef ShrubberyCreationForm_HPP   
#define ShrubberyCreationForm_HPP   

#iinclude "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    void execute(Bureaucrat const & executor) const;

    class FaileOpenException : public exception
    {
        public:
            virtual const char *what() const throw();
    }
}
#endif