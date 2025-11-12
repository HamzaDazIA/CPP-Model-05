#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& str, int grade) : name(str), grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name) , grade(obj.grade)
{}
Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){
    this->grade = obj.grade;

    return (*this);
}


int Bureaucrat::GradeTooHighException() {
    std::cout << "Grade is too high!" << std::endl;

}

float Bureaucrat::GradeTooLowException() {
    std::cout << "Grade is too low!" << std::endl;
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


void Bureaucrat::incrementGrade()
{
    if ()
}

void Bureaucrat::decrementGrade()
{
    if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}