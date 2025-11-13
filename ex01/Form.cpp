#include "Form.hpp"


Form::Form() : name("Default"), grade_signd(50), exec_signd(50){
    this->signd = false;
}

Form::Form(const std::string name, const int sign_grade, const int execute_grade) : name(name) , grade_signd(sign_grade), exec_signd(execute_grade){
    this->signd = false;
    if (sign_grade < 1 || execute_grade < 1)
        throw Form::GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw Form::GradeTooLowException();
}

Form:: Form (const Form &obj) : name(obj.name) , grade_signd(obj.grade_signd), exec_signd(obj.exec_signd)
{
    this->signd = obj.signd;
}


Form &Form::operator=(const Form &obj)
{
    this->signd = obj.signd;
    return (*this);
}

Form::~Form(){}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is to highe");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is to low");
}

void Form::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() <= this->grade_signd)
        this->signd = true;
    else
        throw Form::GradeTooLowException();
}


const std::string Form::getNameForm() const {
    return(name);
}

std::ostream &operator<<(std::ostream &out , Form &obj)
{
    out << obj.getNameForm() << "is Signd " << obj.getSignd() << " Grade Signd "<< obj.getGradeSignd() << " grade required to execute " << obj.getExecSignd() ;
    return (out);
}

bool Form::getSignd() const{ return (signd);}

int Form::getGradeSignd() const
{
    return(grade_signd) ;
}

int Form::getExecSignd() const
{
    return (exec_signd);
}