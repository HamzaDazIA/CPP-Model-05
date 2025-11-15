#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat bob("Bob", 50);
		Form form("Form A", 45, 30);
		
		std::cout << bob << std::endl;
		std::cout << form << std::endl;
		
		bob.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
