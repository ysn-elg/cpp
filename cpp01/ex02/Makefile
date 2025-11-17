NAME		= brain

CPP			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp

OBJ			= main.o

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o:%.cpp
	$(CPP) $(CXXFLAGS) -c $(SRC) -o $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean flean re all

