#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        int GradeTooHighException();
        float GradeTooLowException();
        const std::string getName() const;
        int getGrade() const;
        void setGrade(int grade);
        void incrementGrade();
        void decrementGrade();
        class GradeTooHighExceptionClass : public std::exception {
            public:
                const char* what() const throw();
        };
}  ;
#endif 