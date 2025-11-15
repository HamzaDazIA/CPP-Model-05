
NAME = ex02

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98


SRCS = main.cpp \
       Bureaucrat.cpp \
       AForm.cpp \
       ShrubberyCreationForm.cpp \
       RobotomyRequestForm.cpp \
       PresidentialPardonForm.cpp


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
