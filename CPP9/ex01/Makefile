NAME = RPN
FLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)



all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	c++ $(FLAGS) -c $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
