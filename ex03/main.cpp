#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(std::time(NULL));

	Intern intern;
	AForm *form1;
	AForm *form2;

	form1 = intern.makeForm("shrubbery creation", "home");
	if (form1)
	{
		Bureaucrat bob("Bob", 1);
		bob.signForm(*form1);
		bob.executeForm(*form1);
		delete form1;
	}

	form2 = intern.makeForm("invalid form", "target");
	if (form2)
		delete form2;

	return 0;
}
