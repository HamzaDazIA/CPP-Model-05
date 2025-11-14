#include "RobotomyRequestForm.hpp"
#include <cstdlib>
	
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    this->setTarget("Default");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj)
{
    this->setTarget(obj.getTarget());
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->setTarget(other.getTarget());
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

const char *RobotomyRequestForm::Faildrobotomy::what() const throw()
{
    return ("That the robotomy failed");
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getSignd() == false)
    {
        throw RobotomyRequestForm::FormIsNotSigndException();
    }

    if (this->getExecSignd() < executor.getGrade())
        throw RobotomyRequestForm::GradeTooLowException();
    if (rand() > 50)
    {
        throw::RobotomyRequestForm::Faildrobotomy();
    }
    else if (rand() < 50)
    {
        std::cout << "DRRRRIIIILLLL..." << std::endl;
    }

}
