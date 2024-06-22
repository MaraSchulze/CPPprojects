NAME = btc
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp BitcoinExchange.cpp helperfunctions.cpp
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
