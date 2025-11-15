
NAME = ex03

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98


SRCS = AForm.cpp\
	Bureaucrat.cpp\
	Intern.cpp\
	PresidentialPardonForm.cpp\
	RobotomyRequestForm.cpp\
	ShrubberyCreationForm.cpp\
	main.cpp\


OBJS = $(SRCS:.cpp=.o)

RM = rm -f


all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)


%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

# Rule to clean object files
clean:
	$(RM) $(OBJS)


fclean: clean
	$(RM) $(NAME)


re: fclean all
