void Bureaucrat::signForm(AForm &form) // <-- FIX: Must be AForm&
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getNameAForm() << std::endl;
    }
    catch(AForm::GradeTooLowException &e) // <-- FIX: Must be AForm::
    {
        std::cout << this->getName() << " couldn't sign " << form.getNameAForm() 
                  << " because " << e.what() << std::endl;
    }
}

// <-- FIX: ADD THIS ENTIRE FUNCTION! -->

    catch (std::exception & e)
    {
        std::cout << this->name << " couldn't execute " << form.getNameAForm() 
                  << " because: " << e.what() << std::endl;
    }
