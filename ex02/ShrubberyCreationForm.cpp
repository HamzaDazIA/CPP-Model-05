#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    this->setTarget("Home");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj)
{
    this->setTarget(obj.getTarget());
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->setTarget(other.getTarget());
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char *ShrubberyCreationForm::FaileOpenException::what() const throw()
{
    return ("Fails open file");
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getSignd() == false)
        throw ShrubberyCreationForm::FormIsNotSigndException();
    if (this->getExecSignd() < executor.getGrade())
        throw ShrubberyCreationForm::GradeTooLowException();

    std::string filen_name = getTarget() + "_shrubbery";

    std::ofstream out_file(filen_name.c_str());
    if (!out_file.is_open())
        throw ShrubberyCreationForm::FaileOpenException();
    out_file << "                                                       ." << std::endl;
    out_file << "                                              .         ;  " << std::endl;
    out_file << "                 .              .              ;%     ;;   " << std::endl;
    out_file << "                   ,           ,                :;%  %;   " << std::endl;
    out_file << "                    :         ;                   :;%;'     .,   " << std::endl;
    out_file << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
    out_file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    out_file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
    out_file << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    out_file << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    out_file << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    out_file << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
    out_file << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
    out_file << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
    out_file << "                          `@%%. `@%%    ;@@%;        " << std::endl;
    out_file << "                            ;@%. :@%%  %@@%;       " << std::endl;
    out_file << "                              %@bd%%%bd%%:;     " << std::endl;
    out_file << "                                #@%%%%%:;;" << std::endl;
    out_file << "                                %@@%%%::;" << std::endl;
    out_file << "                                %@@@%(o);  . '         " << std::endl;
    out_file << "                                %@@@o%;:(.,'         " << std::endl;
    out_file << "                            `.. %@@@o%::;         " << std::endl;
    out_file << "                               `)@@@o%::;         " << std::endl;
    out_file << "                                %@@(o)::;        " << std::endl;
    out_file << "                               .%@@@@%::;         " << std::endl;
    out_file << "                               ;%@@@@%::;.          " << std::endl;
    out_file << "                              ;%@@@@%%:;;;. " << std::endl;
    out_file << "                          ...;%@@@@@%%:;;;;,..    " << std::endl;
}