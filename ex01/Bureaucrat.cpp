#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"){
    this->grade = 75;
    
}

Bureaucrat::Bureaucrat(int grad): name("Default"){
    this->grade = grad;

    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();

    if(this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const std::string& str, int grad) : name(str){
    this->grade = grad;

    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();

    if(this->grade > 150)
        throw Bureaucrat::GradeTooLowException();

}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name) , grade(obj.grade)
{
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException(); 
    if(this->grade > 150)
        throw Bureaucrat::GradeTooLowException();   
}
Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){
    this->grade = obj.grade;
    return (*this);
}


const std::string Bureaucrat::getName() const {
    return this->name;
}
int Bureaucrat::getGrade() const {
    return this->grade;
    
}

void Bureaucrat::setGrade(int grade)
{
    this->grade = grade; 
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("The highest possible grade is 1");

}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("The lowest possible grade is 150");
}

std::ostream &operator<<(std::ostream &out , const Bureaucrat &obj)
{
    out << obj.getName() << " , bureaucrat grade " << obj.getGrade() << ".";
    return (out);
}


void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if(this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getNameForm() << std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getNameForm() << " because " << e.what() << std::endl;
    }

}


