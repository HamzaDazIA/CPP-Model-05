#include "AForm.hpp"


AForm::AForm() : name("Default"), grade_signd(50), exec_signd(50) {
    this->signd = false;
    this->target = "Default";
}

AForm::AForm(const std::string name, const int sign_grade, const int execute_grade 
        ) : name(name) , grade_signd(sign_grade), exec_signd(execute_grade){
    this->signd = false;
    this->target = "Default";
    if (sign_grade < 1 || execute_grade < 1)
        throw AForm::GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw AForm::GradeTooLowException();
}

AForm:: AForm (const AForm &obj) : name(obj.name) , grade_signd(obj.grade_signd), exec_signd(obj.exec_signd)
{
    this->signd = obj.signd;
    this->setTarget(obj.getTarget());
}


AForm &AForm::operator=(const AForm &obj)
{
    if (this != &obj) {
        this->signd = obj.signd;
        this->setTarget(obj.getTarget());
    }
    return (*this);
}

AForm::~AForm(){}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char *AForm::FormIsNotSigndException::what() const throw()
{
    return ("Form is not signed");
}

void AForm::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() <= this->grade_signd)
        this->signd = true;
    else
        throw AForm::GradeTooLowException();
}


const std::string AForm::getNameAForm() const {
    return(name);
}

std::ostream &operator<<(std::ostream &out , AForm &obj)
{
    out << "AForm " << obj.getNameAForm() << " is signed: " << obj.getSignd() 
        << ", grade required to sign: " << obj.getGradeSignd() 
        << ", grade required to execute: " << obj.getExecSignd() << std::endl;
    return (out);
}

bool AForm::getSignd() const{ return (signd);}

int AForm::getGradeSignd() const
{
    return(grade_signd) ;
}

int AForm::getExecSignd() const
{
    return (exec_signd);
}


const std::string & AForm::getTarget() const
{
    return (this->target);
}


void AForm::setTarget(std::string traget)
{
    this->target = traget;
}