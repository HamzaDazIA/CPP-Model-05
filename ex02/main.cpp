#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(std::time(NULL));

	try
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur");

		bob.signForm(shrub);
		bob.executeForm(shrub);

		bob.signForm(robot);
		bob.executeForm(robot);

		bob.signForm(pardon);
		bob.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
