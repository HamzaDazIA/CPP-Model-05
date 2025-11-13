#ifndef FORM_HPP
#define FORM_HPP


#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
    private :
        const std::string name;
        bool signd;
        const int grade_signd;
        const int exec_signd;
    public :
        Form();
        Form(const std::string name, const int sign_grade, const int execute_grade);
        Form(const Form &obj);
        Form &operator=(const Form &obj);
        void beSigned(const Bureaucrat &obj);
        const std::string getNameForm() const ; 
        bool getSignd() const;
        int getGradeSignd() const;
        int getExecSignd() const;

        ~Form();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

};

std::ostream &operator<<(std::ostream &out , Form &obj);

#endif 