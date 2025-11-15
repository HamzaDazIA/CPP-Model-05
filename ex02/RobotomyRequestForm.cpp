#include "RobotomyRequestForm.hpp"

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
    
    std::cout << "* drilling noises *" << std::endl;
    
    if (std::rand() % 2 == 0)
    {
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        throw RobotomyRequestForm::Faildrobotomy();
    }
}
