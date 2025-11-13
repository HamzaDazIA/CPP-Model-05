SRC = Bureaucrat.cpp main.cpp  Form.cpp

OBJ = ${SRC:.cpp=.o}

HEADER = Bureaucrat.hpp Form.hpp

NAME = Bureaucrat

CC = c++

FLAG = -Wall -Wextra -Werror -std=c++98


%.o : %.cpp
	${CC} ${FLAG} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${FLAG} ${OBJ} -o ${NAME}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all


