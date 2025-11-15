#ifndef AForm_HPP
#define AForm_HPP


#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
    private :
        const std::string name;
        bool signd;
        const int grade_signd;
        const int exec_signd;
        std::string target;
    public :
        AForm();
        virtual void execute(Bureaucrat const & executor) const = 0;
        AForm(const std::string name, const int sign_grade, const int execute_grade);
        AForm(const AForm &obj);

        AForm &operator=(const AForm &obj);
        void beSigned(const Bureaucrat &obj);
        const std::string getNameAForm() const ; 
        bool getSignd() const;
        int getGradeSignd() const;
        int getExecSignd() const;
        const std::string & getTarget() const;
        virtual ~AForm();
        void setTarget(std::string target);
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

        class FormIsNotSigndException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };


};

std::ostream &operator<<(std::ostream &out , AForm &obj);

#endif 